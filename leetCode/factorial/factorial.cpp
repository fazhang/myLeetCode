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


/*
 *  大整数乘法  输入、输入，均从0开始排列
 */
string BigNumberMulti(string& x , string& y){
	string out(x.size() + y.size(), '0');
	int maxlen = x.size();  
	int carry = 0 ; 
	for( int i = 0 ; i < y.size(); i++){
		int iy = y[i] - '0';
		for( int j = 0 ; j < x.size(); j++){
			int jx = x[j] - '0';
			int outsum = (out[i+j] - '0') + jx*iy + carry;
			out[i+j] = outsum%10 + '0';
			carry =  outsum/10;
		}
		maxlen = i + x.size(); //定位到当前使用位前一步
		int second_carry = 0 ;
		while(carry > 0 || second_carry > 0 ){
			int sum = (out[maxlen] -'0') + (carry%10 ) + second_carry;
			second_carry = sum/10;
			out[maxlen++] = sum%10  + '0';
			carry /= 10;
		}
	}
	out.resize(maxlen);
	return out;
}

/*
 * 思路一：基于字符串，逐位相乘
 */
string factorial_1(int n){
	string out = "1";
	if( n <= 1){ return out; }
	int carry  = 0 ; 
	for( int i = 2; i <= n; i++){
		for( int j = 0 ; j < out.size(); j++){
			int product = i*(out[j] - '0') + carry;
			out[j] = ((product%10) + '0') ;
			carry = product/10;
		}
		while(carry > 0){
			out.push_back(((carry%10) + '0'));
			carry /= 10;
		}
	}
	//这里要反过来输出
	std::reverse(out.begin(), out.end());
	return out;
}


/*
 * 思路二：将中间结果做分而治之
 */

string factorial_2(int n){
	string out = "1";
	if( n <= 1){ return out; }
	for( int i = 2; i <= n; i++){
		string stri = std::to_string(i);
		std::reverse(stri.begin(), stri.end());
		out = BigNumberMulti(out, stri);
		//cout << stri << " " << out << endl;
	}
	std::reverse(out.begin(), out.end());
	return out;
	/*
	int carry  = 0 ; 
	for( int i = 2; i <= n; i++){
		for( int j = 0 ; j < out.size(); j++){
			int product = i*(out[j] - '0') + carry;
			out[j] = ((product%10) + '0') ;
			carry = product/10;
		}
		while(carry > 0){
			out.push_back(((carry%10) + '0'));
			carry /= 10;
		}
	}
	*/

}

/*
 * 思路三：将n也做分而治之
 */

void solu_1 (vector<int>& in){
	vector<int> leftMax(in.size(), 0);
	vector<int> rightMax(in.size(), 0);
	leftMax[0] = in[0];
	rightMax[in.size() -1 ] = in[in.size() -1];
	for( int i = 1 ; i < in.size(); i++){
		leftMax[i] =  std::max(in[i], leftMax[i-1]);
	}
	for( int i = in.size() -2; i >= 0 ; i--){
		rightMax[i] = std::max(in[i], rightMax[i+1]);
	}

	int ans  = 0 ;
	for( int i = 1; i < in.size() -1; i++){
		ans += (std::min( leftMax[i] , rightMax[i]) - in[i]);
	}
	cout << "ans1:" << ans << endl;
}

void solu_2(vector<int>& in){
	int left = 0 ;
	int right = in.size() -1;
	int leftMax = 0 ; 
	int rightMax = 0;
	int ans = 0;
	while(left <= right){
		leftMax = std::max(leftMax, in[left]);
		rightMax = std::max(rightMax, in[right]);
		if( leftMax < rightMax){
			ans += (leftMax - in[left]);
			left ++;
		}else{
			ans += (rightMax - in[right]);
			right --;
		}
	}
	cout << "ans2:" << ans << endl;
}

std::vector<int> makeRandVec( int num, int mod=100){
    std::vector<int> out;
    out.reserve(num);
    for( int i = 0 ; i < num ; i++){
		out.push_back(rand()%mod);
    }
	return out;
}
int main(int argc, char**argv){
    vector<int>  r2Sort;
    srand(Nowms());
    int num = 10;
    if( argc > 1 ){
		num = atoi(argv[1]);
    }

	//vector<int> t = makeRandVec(num);//{6,5,4,3,2,1};
	vector<int> t = {6,5,4,3,2,0,2};
	solu_1(t);
	solu_2(t);
/*
	string a  = argv[1];
	string b = argv[2];
	std::reverse(a.begin(), a.end());
	std::reverse(b.begin(), b.end());
	string out = BigNumberMulti(a,b);
	std::reverse(out.begin(), out.end());
	cout << out << std::endl;
	return 0;
	*/
	
	/*
	uint64_t begin = Nowms();
	string s;
	s = factorial_1(num);
	uint64_t end = Nowms();
	cout << num << " " << s << endl;
	uint64_t t = end  - begin;
	cout << "\t" <<t << endl;

	{
		uint64_t begin = Nowms();
		s = factorial_2(num);
		uint64_t end = Nowms();
		cout << num << " " << s << endl;
		uint64_t t = end  - begin;
		cout << "\t" <<t << endl;
	}
	*/
    return 0;
}
