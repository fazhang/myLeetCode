https://leetcode.com/problems/next-greater-node-in-linked-list/

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ret;
        if( head == nullptr){
            return ret;
        }
        stack<int> s;
        stack<int> index;
        map<int, int> index2val;
        int i= 0;
        while(head != nullptr){
            int val = head->val ;
            if( s.empty()){
                s.push(val);
                index.push(i);
                head = head->next;
                i++;
                continue;
            }

            if( val > s.top()){
                s.pop();
                int i = index.top();
                index.pop();
                index2val[i] =  val;
            }else{
                s.push(val);
                index.push(i);
                head = head->next;
                i++;
            }
        }
        ret.resize(i);
        for( auto s: index2val){
            ret[s.first] = s.second;
        }
        return ret;
    }
};
