https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        if( x == 0 ){
            return 0;
        }
        int64_t n = x;
        if( x > 0 ){
            return reversePositive(n, 1LL << 31);
        }
        return -reversePositive(-n, (1LL << 31) -1 );
    }
    int reversePositive(int x , int64_t max ){
        int m = 0 ;
        int64_t n = 0;

        while( x> 0 ){
            m = x%10;
            x /= 10;
            n = n*10 + m ;
        }
        if( n > max){
            return 0;
        }
        return n ;
    }
};
