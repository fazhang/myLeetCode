https://leetcode.com/problems/implement-strstr/

static auto _=[]()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int strStr(string haystack, string needle) {
    char charHash[256] = {-1};
    for(int i = 0 ; i < needle.size(); i++){
        charHash[ (int)(needle.at(i)) ] = i;
        //后面相同的字符会覆盖掉前面的，不存在的默认是-1
    }
        int M = haystack.size();
        int N= needle.size();
        if( M <  N){
            return -1;
        }
        int i=0, j=0;
        int skip =1;
        for( i = 0 ; i <= M-N; i += skip ){
            for( j = 0 ; j < N ; j ++){
                char s = haystack.at(i + j );
                char t = needle.at(j) ;
                if( s != t ){
                    if( i == M - N)
                        break;
                  skip = N - charHash[ haystack.at(i + N)];
                  break;  //少了这一句就会错
                }
            }
            if( j == N )
            return i ;
        }
        return -1;
    }
};
