#include <stdio.h> 
#include <string>  
#include <iostream>  

using namespace std;
class Solution {
public:
//采用SunDay 算法实现
//借鉴https://www.cnblogs.com/linbingdong/p/6479537.html 
//但原地址getIndex 引入了多余的复杂度，应当使用固定存储空间扫描一次即可

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
        int skip = 1;
        for( i = 0 ; i <= M-N; i += skip ){
        cout << "i: " << i << endl;
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

int main(int argc, char**argv){
    Solution s;
    string txt;
    string pat;
    cin >> txt;
    cin >> pat;
    cout << s.strStr(txt,pat) << endl;
}
