#include <stdio.h> 
#include <string>  
#include <iostream>  
#include <vector>  
#include <iomanip>
using namespace std;
//蓄水池采样算法
//在一个不确定N数量，或者是流式的系统中，如何确保每个元素采集的概率相等
// 

//从一个无限的流里面，取K个值
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

int sampling( int K){

    vector<int>  sampleVec(K);
    srand(time(nullptr));

    int count = 0 ;

    for ( int i = 0 ; i < 500000; i++){
        int ir = rand()%10000;
        if( i < K ){
            sampleVec[i] = ir;
            continue;
        }

        int r = rand()%(i+1) ;
        //    cout <<"i:"<< i <<  " r: " << r <<  " K: " << K << " ir:" << ir << endl;
        if( r < K){
            sampleVec[r] = ir;
            if( i %10000){
            count ++;
                //cout << i <<  "  " << r << " " << K << " " << ir << endl;
            }
        }
        static bool firstPrint = true;
        if( firstPrint ){
            firstPrint = false;
            outputVec(sampleVec);
        }
    }
    outputVec(sampleVec);
    cout << ">>>>>>>>>>>>>>>>>>>>>>END>>>>>>>>>>>>>>>>>>>>>>>" << count << endl;
    return 0;
}

int main(int argc, char**argv){
    sampling(30);
    return 0;
}
