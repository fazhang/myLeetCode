https://leetcode.com/problems/longest-valid-parentheses/
https://blog.csdn.net/hunt_ing/article/details/82822912
//多种解法
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>  lenStack;
        int max = 0 ;
        //int maxTailIndex = 0;
        //int lastLen = 0 ;
        if( s.size() < 2){
            return 0;
        }
        lenStack.push(-1);
        //vector<int> maxVec(s.size()+1, 0 );
        for( int i = 0 ; i < s.size(); i++){
            char x = s[i];
            if( x == ')' ){
                lenStack.pop();//这个值可以将匹配的弹出来
                if(lenStack.empty()){
                    lenStack.push(i);
                }else{
                    max = std::max(max, i- lenStack.top());
                }
            }else{
                lenStack.push(i);
            }
        }
        return max;
    }
};
