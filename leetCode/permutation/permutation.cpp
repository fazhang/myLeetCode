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


class Solution{
	public:
		vector<vector<char>> permute(vector<char>& in) {
			std::sort(in.begin(), in.end());
			tmp_in = in;
			tmp.resize(in.size());
			total = in.size();
			visit.resize(in.size(), true);

			dfs(0);
			return ret;
		}
		void dfs( int count){
			if (count == total){
				ret.push_back(tmp);
				return ;
			}
			for( int i = 0 ;i < total ; i++){
				if( visit[i]){
					visit[i] = false;
					tmp[count] = tmp_in[i];
					dfs(count+1);
					visit[i] = true;
				}
				if( count == 0){
					ret.push_back({});
				}
			}
		}
	public:
		vector<vector<char> > ret;
		vector<char> tmp;
		vector<bool> visit;
		vector<char> tmp_in;
		int total ;
};


int main(int argc, char**argv){
    vector<int>  r2Sort;
    srand(Nowms());
    int num = 5;
	vector<char> t ;
	for( int i = 0 ; i < 26; i ++){
		t.push_back(i+'a');
	}
    if( argc > 1 ){
        num = atoi(argv[1]);
    }
	vector<char> n(t.begin(), t.begin() + num);
	if( argc > 2){
		const char* in = argv[2];
		n.clear();
		n.resize(strlen(in));
		for( int i = 0 ; i < strlen(in); i++){
			n[i] = in[i];
		}
	}
    //outputVec(r2Sort);
	Solution s;
	auto m = s.permute(n);
	for( auto i : m){
		for( auto j: i){
			cout << j << " " ;
		}
		cout << endl;
	}

    return 0;
}
