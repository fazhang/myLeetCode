https://leetcode.com/problems/valid-parentheses/

class Solution {
public:

    bool isLeft(char c){
        if( c == '('
          || c == '{'
          || c == '['){
            return true;
        }
        return false;
    }
    bool isSameType(char x, char c){
        if( (c == '(' && x == ')')
           ||(c == '[' && x == ']')
           ||(c == '{' && x == '}')
           ){
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        if(s.empty()){
            return true;
        }
        std::stack<char> validStack;
        for( auto c : s ){
            if( isLeft(c)){
                validStack.push(c);
                continue;
            }
            if(validStack.empty()){
                return false;
            }else{
                char x = validStack.top();
                if(!isSameType(c,x) ){
                    return false;
                }
                validStack.pop();
            }
        }
        return validStack.empty();
    }
};
