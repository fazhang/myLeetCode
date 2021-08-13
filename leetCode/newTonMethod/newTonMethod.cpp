//牛顿迭代法求平方根
#include <stdio.h> 
#include <string>  
#include <iostream>  
#include <vector>  
#include <iomanip>
#include <memory>
#include <deque>
#include <queue>
#include <stack>
#include <math.h>
#include <sys/time.h>

using namespace std;


  struct TreeNode {
	  int index;
      int val;
      TreeNode *left;
      TreeNode *right;
	  TreeNode(){}
      TreeNode(int x,int i) : val(x),index(i), left(NULL), right(NULL) {}
  };

double mySqrt(double in){
    if( in <= 0.0 ){
        return 0;
    }
    double fstart = in/2; // 从in/2 开始试探
    double  err = 1e-8; 
    while( abs(in - fstart*fstart) >  err){
        fstart = (in/fstart + fstart)/2.0;
    }
    return fstart;
}

uint64_t  Nowms()
{
  timeval tvNow;
  gettimeofday(&tvNow, NULL);
  return tvNow.tv_sec* 1000 +  tvNow.tv_usec/1000;
}
void outputVec(const vector<int>& in){
    size_t sep = 10;
    size_t cnt = 0;
    for( auto i : in){
        cout <<setiosflags(ios::left)<<setw(8);
        cout << i << " ";
        if( (cnt)%sep == 9){
            cout << endl;
        }
        cnt ++;
    }
    cout << endl;
}

int mySqrt(int x) {
	if( x <= 1){
		return x;
	}
	int m = x/2;
	while( m*m > x){
		m = m/2;
	}
	//找到一个m*m  比x 小了。 还需要继续加
	int n = m;
	while( n*n <= x ){
		n++;
	}
	return n-1;
}
vector<vector<int>> generate(int numRows) {
	vector<vector<int > > out(numRows,{});
	if( numRows > 0){
		out[0].push_back(1);
	}
	if( numRows > 1){
		out[1].push_back(1);
		out[1].push_back(1);
	}
	for(int i = 2 ; i < numRows;i++){
		vector<int>& local = out[i];//取个引用
		local.resize(i+1);
		vector<int>& last = out[i-1];
		local[0] = 1;
		local[i] = 1;
		for( int j = 1; j < i ; j++){
			local[j] = last[j-1] + last[j];
		}
	}
	return out;
}

class Solution125 {
public:
    bool isAlpha(char c ){
        if( 'a' <= c &&  c<= 'z'){
            return true;
        }
        if( 'A' <= c &&  c<= 'Z'){
            return true;
        }
        return false;
    }
    bool isEqual(char x, char y){
        if( x == y){
            return true;
        }
        if( 'A' <= x &&  x<= 'Z'){
            if( (x - 'A') == (y - 'a')){
                return true;
            }
        }
        if( 'a' <= x &&  x<= 'z'){
            if( (x - 'a') == (y - 'A')){
                return true;
            }
        }

        return false;
    }
    bool isPalindrome(string s) {
        if(s.empty()){
            return true;
        }
        int i = 0 ;
        int j = s.size() -1;
        while(i <= j){
            while(!isAlpha(s[i]) && i < j-1 ){
                i++;
            }
            if(!isAlpha(s[i])){
                return true;
            }
            while(!isAlpha(s[j]) && j > 0 ){
                j--;
            }
			printf("i:%d j:%d %c %c  %d %d \n",i,j,s[i],s[j], isAlpha(s[i]), isAlpha(s[j]));
            if( !isEqual(s[i],s[j]) ){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

string convertToTitle(int n){
	 string res;
        while (n != 0) {
            int temp = n%26;
            //special case
            if (temp == 0) {
                n-=26;
                temp = 26;
            }
            res.insert(res.begin(), char(temp + 'A' - 1));
            n/=26;
        }
        return res;
}


class Solution_236 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, int a, int b) {
        stack<TreeNode*> root2node;

		/*
        if( p == q ){
            return p ;
        }
		*/

        TreeNode* raw_root = root;
        bool bFind = checkNode(root,a,b);
		cout << "bFind " << bFind << endl;
       if(!bFind){
           return nullptr;
       }
        TreeNode* last = nullptr;
		cout << "pQueue.size:"<< pQueue.size() << " qQueue:" << qQueue.size() << endl;
        while(!pQueue.empty() && !qQueue.empty()){
            TreeNode* p1 = pQueue.front();
            TreeNode* p2 = qQueue.front();
			printf("p1:%x p2:%x \n", p1, p2);
            if( p1 != p2){
                break;
            }
            pQueue.pop();
            qQueue.pop();
            last = p1;
        }
		cout << "pQueue.size:"<< pQueue.size() << " qQueue:" << qQueue.size() << endl;
        return last;
    }
    bool checkNode(TreeNode*cur, int p , int q){
        if( cur == nullptr){
            return false;
        }
        tracing.push(cur);
        if( pQueue.empty() && cur->val == p ){
                pQueue = tracing;
				printf("pQueuefront %x \n", pQueue.front());
        }
        if( qQueue.empty() && cur->val == q){
                qQueue = tracing;
				printf("qQueuefront %x \n", qQueue.front());
        }

        if(!pQueue.empty() && !qQueue.empty()){
            return true;
        }
        TreeNode* left  = cur->left;
        TreeNode* right  = cur->right;
        bool bFind = checkNode(left,q,p);
        if(bFind){
            return bFind;
        }
        bFind = checkNode(right,q,p);
        if(bFind){
            return bFind;
        }
        tracing.pop();
        return false;
    }

    public:
    queue<TreeNode*> tracing;
    queue<TreeNode*> pQueue;
    queue<TreeNode*> qQueue;
};

TreeNode* makeTree(vector<int>& in){
	if( in.empty()){
		return nullptr;
	}
	TreeNode* root = new TreeNode(in[0], 1);
	deque<TreeNode*> nodeQ;
	nodeQ.push_back(root);
	while(!nodeQ.empty()){
		TreeNode* p = nodeQ.front();
		nodeQ.pop_front();
		int left = p->index*2;
		int right= p->index*2 +1;
		cout << nodeQ.size() << " " << p->index << " " << left << " " <<  right  << endl;
		if( left <= in.size() && in[left-1] != -1  ){
			p->left = new TreeNode(in[left-1], left);
			nodeQ.push_back(p->left);
		}
		if(  right <= in.size() && in[right-1] != -1 ){
			p->right= new TreeNode(in[right-1], right);
			nodeQ.push_back(p->right);
		}
	}
	return root;
}

void outputTreeNode(TreeNode* p){
	queue<TreeNode*>  nodeQ;
	nodeQ.push(p);
	int size = nodeQ.size();
	while(!nodeQ.empty()){
		p = nodeQ.front();
		if( p  != nullptr){
			TreeNode* left = p->left;
			TreeNode* right = p->right;
			nodeQ.push(left);
			nodeQ.push(right);
			cout << p->val << " " ;
		}else{
			cout << -1  << " " ;
		}
		nodeQ.pop();
		size --;
		if( size == 0){
			cout << endl;
			size = nodeQ.size();
		}

	}
}

int main(int argc, char**argv){
    vector<int>  r2Sort;
    srand(Nowms());
	int num = 100;
	if( argc > 1){
		num = atoi(argv[1]);
	}

	/*
	for( int i = 1 ; i < num; i++){
		cout << i << "->  " << convertToTitle(i) << endl;
	}
	*/
	vector<int> tmp = {3,5,1,6,2,0,8,-1,-1,7,4};

	TreeNode* p = makeTree(tmp);
	outputTreeNode(p);
	Solution_236 s;
	TreeNode* ret = s.lowestCommonAncestor(p, 2, 8);
	cout << ret << endl;

    return 0;
}

