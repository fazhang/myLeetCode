https://leetcode.com/problems/backspace-string-compare/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> stackS;
        stack<char> stackT;
        for(int i = 0 ; i < S.size() ;i++){
            char x = S[i];
            if( x != '#'){
                stackS.push(x);
            }else{
                if( !stackS.empty()){
                    stackS.pop();
                }
            }
        }
        for(int i = 0 ; i < T.size() ;i++){
            char x = T[i];
            if( x != '#'){
                stackT.push(x);
            }else{
                if( !stackT.empty()){
                    stackT.pop();
                }
            }
        }
        
        if( stackS.size() != stackT.size()){
            return false;
        }
        while( !stackS.empty()){
            char x = stackS.top();
            char y = stackT.top();
            if( x != y){
                return false;
            }
            stackS.pop();
            stackT.pop();
        }
        return true;
    }
    //来写两种解决
    //1 用stack 来解决
    //2 用指针反向来解决
};
