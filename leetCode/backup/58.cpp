https://leetcode.com/problems/length-of-last-word/

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()){
            return 0;
        }
        int last = s.size() -1;

        while( last >= 0){
            char c = s[last];
            if( c != ' '){
                break;
            }
            last--;
        }
        int t = last;//倒数第一个非空格字符
        if( t < 0){
            return 0;
        }
        while (t >= 0){
            char c = s[t];
            if( c == ' '){
                break;
            }
            t--;
        }
        return last - t ;
    }
};
