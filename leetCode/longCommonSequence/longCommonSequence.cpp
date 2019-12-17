#include <stdio.h> 
#include <string>  
#include <iostream>  
#include <vector>  
#include <iomanip>

using namespace std;
//最长公共子序列， 算法导论的经典算法
//类似的还有矩阵乘法、车间装载、N个鸡蛋M层掉下等
//采用动态规划的思路来实现

// 首先要得到递归公式
// 然后用备忘录思路， 再优化为自底而上的递推法
// 最后优化中间使用的临时空间


const char buf[] = {'C','A','G','T'};


//返回最长公共子序列的长度
//str3 = 其中一个最长公共子序列的内容
//代码可读性不是太强，待优化，网上很多代码容易出现m 这个中转区处理不当
//尤其是对m[0][j] m[i][0]  初始行列未初始化  
//将O(M*N) 优化为O(max(N))
int myLCS(string& str1, string& str2,  string& str3){
    int len1 = str1.size();
    int len2 = str2.size();

    int msize = (2)*(len2+1);
    int* m = new int[msize];
    memset(m,0, msize); 
    //m[i][j] 代表的是str1[i-1]  与str2[j-1]  的最长公共子序列
    //其中第0列， 第0行，专门用于初始化，表示str1为0时， str2 为0时， 公共串为0 
    //便于计算
    for( int i = 0 ; i < len2+1; i++){
        m[0*(len2+1) + i] = 0 ;  //第一行
    }
    for( int i = 0 ; i < 2; i++){
        m[i*(len2+1) + 0] = 0 ;  //第一列
    }
    for ( int i = 1 ; i < len1 +1 ; i++){
        for( int j = 1 ; j < len2+1; j++){ //0 已经用掉了
            if(str1.at(i-1) == str2.at(j-1)){
                //m[i*(len2+1) + j] = m[(i-1)*(len2+1) + j-1] +1; //最后一位相等的情况
                m[1*(len2+1) + j] = m[(0)*(len2+1) + j-1] +1; //最后一位相等的情况
                continue;
            }
            //m[i*(len2+1) + j] = max( m[(i-1)*(len2+1) + j ] , m[i*(len2+1) + j-1]);
            m[(len2+1) + j] = max( m[(0)*(len2+1) + j ] , m[1*(len2+1) + j-1]);
        }
        //执行完一轮后，要把 m[1] 的复制到m[0] 去
        //最后一轮可以不复制了
        if( i == 1 ){
        for( int k = 0  ; /*i<len1 && */ k < len2 +1 ; k++){
            cout << int(m[k]) << "  " ;
        }
        cout << endl;
        }
        for( int k = 0  ; /*i<len1 && */ k < len2 +1 ; k++){
            m[k] = m[len2+1 + k] ; 
            cout << int(m[k]) << "  " ;
        }
        cout << endl;
    }
    cout <<  "LongCommonSequence: " << int(m[msize-1]) << endl;
    /*
    for( int i = 0 ; i < 2; i++){
        for( int j = 0 ; j < len2+1 ; j ++){
            cout << int(m[i*(len2+1) + j ]) << " "  ;
        }
        cout << endl; 
    }
    */
    /*
    for( int i = 0 ; i < len1+1; i++){
        for( int j = 0 ; j < len2+1 ; j ++){
            cout << int(m[i*(len2+1) + j ]) << " "  ;
        }
        cout << endl; 
    }
    */
    return 0;
}


void initRandString(string& instr, int len){
    instr.resize(len);
    //C A G T   DNA 四个碱基
    for(int i = 0 ; i < len ; i++){
        instr[i] = buf[rand()%4];
    }
    cout << "init End " << instr  << " " << instr.size()<< endl;
}

int main(int argc, char**argv){
    srand(time(nullptr));
    string str1, str2, str3;
    int len1 = 10; 
    int len2 = 10;
    if( argc > 2 ){
        len1 = atoi(argv[1]);
        len2 = atoi(argv[2]);
    }
    initRandString(str1, len1);
    initRandString(str2, len2);
    cout << str1 <<  endl << str2 << endl;
    myLCS(str1,str2,str3);
    return 0;
}
