//牛顿迭代法求平方根
#include <stdio.h> 
#include <string>  
#include <iostream>  
#include <vector>  
#include <iomanip>
#include <memory>
#include <math.h>
#include <sys/time.h>

using namespace std;

double mySqrt(double in){
    if( in <= 0.0 ){
        return 0;
    }
    double fstart = in/2; // 从in/2 开始试探
    double  err = 1e-8; 
    while( abs(in - fstart*fstart) >  err){
        fstart = (in/fstart + fstart)/2.0;
    }
    return fstart;
}

uint64_t  Nowms()
{
  timeval tvNow;
  gettimeofday(&tvNow, NULL);
  return tvNow.tv_sec* 1000 +  tvNow.tv_usec/1000;
}
void outputVec(const vector<int>& in){
    size_t sep = 10;
    size_t cnt = 0;
    for( auto i : in){
        cout <<setiosflags(ios::left)<<setw(8);
        cout << i << " ";
        if( (cnt)%sep == 9){
            cout << endl;
        }
        cnt ++;
    }
    cout << endl;
}

int main(int argc, char**argv){
    vector<int>  r2Sort;
    srand(Nowms());
    int number = rand()%40;

    cout << "number:" << number << endl;
    cout << "mySqrt:" << mySqrt(number) << endl;
    cout << "math.sqrt:" << sqrt(number) << endl;

    return 0;
}

