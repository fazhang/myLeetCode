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

vector<int> findMax(vector<int>num)
{
	if(num.size()==0)return num;
	vector<int>res(num.size());
	int i=0;
	stack<int>s;
	while(i<num.size())
	{
		if(s.empty()||num[s.top()]>=num[i])
		{
			s.push(i++);
		}
		else
		{
			res[s.top()]=num[i];
			s.pop();
		}
	}
	while(!s.empty())
	{
		res[s.top()]=-1;
		s.pop();
	}
	for(int i=0; i<res.size(); i++)
		cout<<res[i]<<endl;
	return res;
}

vector<int> makeRandVec( int num, int mod=100){
    vector<int> out;
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
	auto r = {3,4,5,5,5,6,7};//makeRandVec(num);
	auto s = findMax(r);
	outputVec(r);
	outputVec(s);
	return 0;
}
