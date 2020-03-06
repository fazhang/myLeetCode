#include <stdio.h> 
#include <string>  
#include <iostream>  
#include <vector>  
#include <iomanip>
#include <memory>
#include <unordered_map>
#include <sys/time.h>
using namespace std;

struct Node{
    public:
		Node(){}
		Node(int k , int v ):key(k),val(v){}
    int val ;
    int key ;
    Node* next;
    Node* prev;
};

class DoubleLinkList{
    public:
    DoubleLinkList():mSize(0){
        dummy.next = &tail;
        dummy.prev = nullptr;
		tail.next = nullptr;
		tail.prev = &dummy;

    }

    void addHeadNode(Node* x){
        Node* next = dummy.next;
        dummy.next = x;
        x->next = next;
		x->prev = &dummy;
		if( next != nullptr){
			next->prev = x;
		}
		mSize ++;
    }
    void removeNode(Node* x){
        Node* prev = x->prev;
        Node* next = x->next;
        prev->next = next;

		if( next != nullptr){
			next->prev = prev;
		}
		mSize --;
    }
    Node* removeLast( ){
        if(size() == 0){
            return nullptr;
        }
		mSize --;
        Node* last = tail.prev ;
        Node* newlast = last->prev;
        newlast->next = &tail;
        tail.prev  = newlast;

		last->next = nullptr;
        last->prev=  nullptr;
        return last;
    }
    int size(){
        return mSize;
    }
    private:
    int mSize ;
    Node dummy;
    Node tail;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    int get(int key) {
		auto it =   nodemap.find(key) ;
		if( it == nodemap.end()){
			return -1;
		}
		int val =  it->second->val ;
		put(key, val);
		return val;
    }
    void put(int key, int value) {
       Node* x = new Node(key,value);
	   auto it = nodemap.find(key);
	   if( it != nodemap.end()){
		   doubleList.removeNode(it->second);
		   doubleList.addHeadNode(x);
		   nodemap[key] = x;
	   }
	   else{
		   if( cap == doubleList.size()){
			   Node* x = doubleList.removeLast();
			   nodemap.erase(x->key);
		   }
		   doubleList.addHeadNode(x);
		   nodemap[key] = x;
	   }
		   
    }
    std::unordered_map<int,Node*>  nodemap;
    DoubleLinkList  doubleList;
    int cap ;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(int argc, char**argv){
	LRUCache* cache = new LRUCache( 2 /* capacity */ );

	cache->put(1, 1);
	cache->put(2, 2);
	cache->get(1);       // returns 1
	cache->put(3, 3);    // evicts key 2
	cout << __LINE__ << endl;
	cache->get(2);       // returns -1 (not found)
	cout << __LINE__ << endl;
	cache->put(4, 4);    // evicts key 1
	cout << __LINE__ << endl;
	cache->get(1);       // returns -1 (not found)
	cout << __LINE__ << endl;
	cache->get(3);       // returns 3
	cout << __LINE__ << endl;
	cache->get(4);       // returns 4
	cout << __LINE__ << endl;
    return 0;
}
