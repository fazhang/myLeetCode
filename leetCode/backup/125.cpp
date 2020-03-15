https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isAlpha(char c ){
        if( 'a' <= c &&  c<= 'z'){
            return true;
        }
        if( 'A' <= c &&  c<= 'Z'){
            return true;
        }
        if( '0' <= c &&  c<= '9'){
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
            if( !isEqual(s[i],s[j]) ){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
