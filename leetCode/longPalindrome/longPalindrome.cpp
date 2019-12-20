#include <stdio.h> 
#include <string>  
#include <iostream>  
#include <vector>  
#include <iomanip>
#include <memory>
#include <sys/time.h>
using namespace std;

uint64_t  Nowms()
{
  timeval tvNow;
  gettimeofday(&tvNow, NULL);
  return tvNow.tv_sec* 1000 +  tvNow.tv_usec/1000;
}

int isPalind(const string& str){
    char* head = const_cast<char*>(str.c_str());
    char* tail = const_cast<char*>(str.data() + str.size() -1 );
    for( ; head < tail  ; head++, tail --){
        if( *head != *tail ){
            return false;
        }
    }
    return true;
}

int  maxExpand(const string& str, int i , int j ){
    int cnt = 0 ;
    while ( i >= 0  && j <str.size() ){
        if( str[i] == str[j] ){
            cnt ++;
            i--;
            j++;
            continue;
        }
        return cnt;
    }
    return cnt;
}


void longSub_dp(const string& str, int& start, int& end ){
    vector<int> dp1(str.size());
    vector<int> dp2(str.size());
    //用两个数组，分别保存 [i,i]  [i,i+1]  的情况
    int max1 = 0;
    int max2 = 0;

    int maxIndex1 = 0;
    int maxIndex2 = 0;
    for( int i = 0 ; i < str.size(); i++){
        dp1[i] = maxExpand(str,i,i);
        dp2[i] = maxExpand(str,i,i+1);
        if(dp1[i] > max1){
            max1 = dp1[i];
            maxIndex1 = i;
        }
        if(dp2[i] > max2){
            max2 = dp2[i];
            maxIndex2 = i;
        }
    }
    if( max1>= max2){
        start =   maxIndex1 - dp1[maxIndex1]+1;
        end =   maxIndex1 + dp1[maxIndex1] -1 ;
    }else{
        start =   maxIndex2 - dp2[maxIndex2];
        end =   maxIndex2 + dp2[maxIndex2] + 1;
    }
}

int main(int argc, char**argv){
    srand(Nowms());
    string s = "";//"abababababababbabdadgagdagagadsdfalsdfa";
    if( argc > 1){
        s = argv[1];
    }
    for( int i = 0 ; i < 30; i ++){
        s += ('a' + rand()%5 );
    }
    cout <<s << " " << (isPalind(s)?"true":"false") << endl;
    int start, end;
    longSub_dp(s, start,end);
    cout <<  " " << start << " " << end << endl;
    cout << s.substr(start,end-start+1) << " " << start << " " << end << endl;
    return 0;
}
