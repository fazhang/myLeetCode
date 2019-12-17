#include <stdio.h> 
#include <string>  
#include <vector>  
#include <iostream>  
//数正方形
//https://www.cnblogs.com/lifexy/p/7550159.html  

using namespace std;

int initSquare(vector<int>& in, int m , int n ){
	//生成m * n 个 0 1 
	srand(time(nullptr));
	in.resize(m*n);
	for( int i = 0 ; i < m*n ; i ++){
		if(rand()%30 > 1){
			in[i] = 1;
		}else{
			in[i] = 0;
		}
	}
	for( int i = 0 ; i < m ; i++){
		for( int j = 0 ; j < n ; j++){
			cout << in[i*m + j ] << " " ;
		}
		cout << endl;
	}
	return 0;
}

//数一数这个M*N的地， 最大的正方形
//数一数有从2 ~max 分别有多少个
int countSquare(vector<int>& in, int m , int n ){
	vector<int> squareCnt(max(m,n));
	//这里如果不改原数据
	//使用一个临时存储，由于只使用到i-1  i 两行
	//因为也可以优化占用空间为O(m)
	for( int i = 1 ; i < m ; i++){
		for( int j = 1 ; j < n ; j++){
			if( in[ i*m + j ] != 0 ){
				int min = std::min( std::min( in[ (i-1)*m + j ] ,  in[(i-1)*m + j-1] ) , in[i*m + j-1]);
				in[i*m + j ] = min+1;
				for( int cnt = 2; cnt <= min+1; cnt++){
					squareCnt[cnt] ++;
				}
			}
		}
	}
	cout << endl;

	for( int i = 0 ; i < m ; i++){
		for( int j = 0 ; j < n ; j++){
			cout << in[i*m + j ] << " " ;
		}
		cout << endl;
	}
	cout << endl;
	for( int i = 2; i < max(m,n); i++){
		cout << "i:" << i <<" " << squareCnt[i] << endl;
	}


	return 0;
}

int main(int argc, char**argv){
	int m = 10; 
	int n = 10;
	vector<int> newSquare;
	if( argc > 2 ){
		m  = atoi(argv[1]);
		n  = atoi(argv[2]);
	}
	initSquare(newSquare, m, n);
	countSquare(newSquare, m, n);
    return 0;
}
