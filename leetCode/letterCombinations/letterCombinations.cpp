#include <stdio.h> 
#include <string>  
#include <iostream>  
#include <vector>  
#include <iomanip>
#include <map>
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

map<char, vector<char> > digit2Char;
vector<string> letterCombinations(string digits) {
	vector<string> tmp ;
	vector<string> tmp2 ;
	if( digits.size() > 1){
		tmp2 = letterCombinations(digits.substr(1,digits.size() -1));
	}
	vector<char>& td = digit2Char[digits[0]];
	for( auto c : td){
		if( tmp2.empty()){
			tmp.push_back(string("") + c );
		}else{
			for( auto i : tmp2){
				tmp.push_back( c + i);
			}
		}
	}
	return tmp;
}

int main(int argc, char**argv){
    vector<int>  r2Sort;
    srand(Nowms());
    int num = 10;
    if( argc > 1 ){
        num = atoi(argv[1]);
    }


	//string digits = argv[1];

	digit2Char['1'] = {};
	digit2Char['2'] = {'a','b','c'};
	digit2Char['3'] = {'d','e','f'};
	digit2Char['4'] = {'g','h','i'};
	digit2Char['5'] = {'j','k','l'};
	digit2Char['6'] = {'m','n','o'};
	digit2Char['7'] = {'p','q','r','s'};
	digit2Char['8'] = {'t','u','v'};
	digit2Char['9'] = {'w','x','y','z'};
	digit2Char['0'] = {' '};

	vector<string> t = letterCombinations("23113");

	for( auto s : t){
		cout << s << endl;
	}

    return 0;
}
