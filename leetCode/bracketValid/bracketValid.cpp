#include <stdio.h> 
#include <string>  
#include <iostream>  
#include <vector>  
#include <iomanip>
#include <memory>
#include <stack>
#include <sys/time.h>
using namespace std;

uint64_t  Nowms()
{
  timeval tvNow;
  gettimeofday(&tvNow, NULL);
  return tvNow.tv_sec* 1000 +  tvNow.tv_usec/1000;
}

bool isValid(const string& in){
	std::stack<char> brackStack;
	if(in.empty()){
		return true;
	}
	for( int i = 0 ; i < in.size(); i++){
		char c = in[i];
		if( c == '('){
			brackStack.push(c);
			continue;
		}
		if( c == ')'){
			if(brackStack.empty()){
				return false;
			}
			brackStack.pop();
		}
	}
	if( brackStack.empty()){
		return true;
	}
	return false;
}

int  longSubStr(const string& in){
	int inSize = in.size();
	int max = 0 ;
	std::stack<int>  indexStack;
	indexStack.push(-1);
	for( int i = 0 ; i < inSize; i++){
		char c = in[i];
		if( c == '('){
			indexStack.push(i);
			continue;
		}
		if( c == ')'){
			indexStack.pop(); //可以确保不会有空的
			if(indexStack.empty()){
				indexStack.push(i);
				continue;
			}else{
				max = std::max(max, i - indexStack.top());
			}
		}
	}
	return max;
	//这里怎么用DP
}

string makeBracket(int num){
	string str;
	str.resize(num);
	for(int i = 0 ; i < num ; i++){
			str[i] = '(';
		if(rand()%10 >6 ){
			str[i] = ')';
		}
	}
//	cout << hex << (void*)(str.c_str()) << endl;
	return str;
}

int main(int argc, char**argv){
    vector<int>  r2Sort;
    srand(Nowms());
    int num = 10;
    if( argc > 1 ){
        num = atoi(argv[1]);
    }
	string&& str = std::move(makeBracket(num));
	//采用右值引用， 可以延长生命周期，减少一次对象复制
	cout << str <<  " " << isValid(str)  <<  endl;
	cout << longSubStr(str) << endl;
    return 0;
}
