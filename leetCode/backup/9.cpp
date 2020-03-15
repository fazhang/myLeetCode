https://leetcode.com/problems/palindrome-number/

class Solution {
public:

    bool isPalindrome(int x) {
        if( 0 == x ){
            return true;
        }
         if( x < 0 ){
            return false;
        }

        int64_t n = x ;
        int64_t m = 0;
        while(n> 0 ){
            m = m*10 + n%10;
            n /= 10;
        }
        if( m == x){
            return true;
        }
        return false;
    }
};

