https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
        if( x <= 1){
            return x;
        }
        int m = x/2;
        while( m > x/m){
            m = m/2;
        }
        //找到一个m*m  比x 小了。 还需要继续加
        int n = m;
        while( n <= x/n ){
            n++;
        }
        return n-1;
    }

};
