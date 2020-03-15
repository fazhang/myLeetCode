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

int mySqrt(int x) {
	if( x <= 1){
		return x;
	}
	int m = x/2;
	while( m*m > x){
		m = m/2;
	}
	//找到一个m*m  比x 小了。 还需要继续加
	int n = m;
	while( n*n <= x ){
		n++;
	}
	return n-1;
}
vector<vector<int>> generate(int numRows) {
	vector<vector<int > > out(numRows,{});
	if( numRows > 0){
		out[0].push_back(1);
	}
	if( numRows > 1){
		out[1].push_back(1);
		out[1].push_back(1);
	}
	for(int i = 2 ; i < numRows;i++){
		vector<int>& local = out[i];//取个引用
		local.resize(i+1);
		vector<int>& last = out[i-1];
		local[0] = 1;
		local[i] = 1;
		for( int j = 1; j < i ; j++){
			local[j] = last[j-1] + last[j];
		}
	}
	return out;
}

class Solution125 {
public:
    bool isAlpha(char c ){
        if( 'a' <= c &&  c<= 'z'){
            return true;
        }
        if( 'A' <= c &&  c<= 'Z'){
            return true;
        }
        return false;
    }
    bool isEqual(char x, char y){
        if( x == y){
            return true;
        }
        if( 'A' <= x &&  x<= 'Z'){
            if( (x - 'A') == (y - 'a')){
                return true;
            }
        }
        if( 'a' <= x &&  x<= 'z'){
            if( (x - 'a') == (y - 'A')){
                return true;
            }
        }

        return false;
    }
    bool isPalindrome(string s) {
        if(s.empty()){
            return true;
        }
        int i = 0 ;
        int j = s.size() -1;
        while(i <= j){
            while(!isAlpha(s[i]) && i < j-1 ){
                i++;
            }
            if(!isAlpha(s[i])){
                return true;
            }
            while(!isAlpha(s[j]) && j > 0 ){
                j--;
            }
			printf("i:%d j:%d %c %c  %d %d \n",i,j,s[i],s[j], isAlpha(s[i]), isAlpha(s[j]));
            if( !isEqual(s[i],s[j]) ){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

string convertToTitle(int n){
	 string res;
        while (n != 0) {
            int temp = n%26;
            //special case
            if (temp == 0) {
                n-=26;
                temp = 26;
            }
            res.insert(res.begin(), char(temp + 'A' - 1));
            n/=26;
        }
        return res;
}

int main(int argc, char**argv){
    vector<int>  r2Sort;
    srand(Nowms());
	int num = 100;
	if( argc > 1){
		num = atoi(argv[1]);
	}

	for( int i = 1 ; i < num; i++){
		cout << i << "->  " << convertToTitle(i) << endl;
	}

    return 0;
}

