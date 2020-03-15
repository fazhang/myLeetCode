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

int searchInsert(vector<int>& nums, int target) {

	if( nums.empty()){
		return 0;
	}
	//有点二分查找的意思。。。
	int left = 0 ;
	int right = nums.size()-1;
	while(left < right){
		int m = (left + right +1 )/2;
		int mval = nums[m];
		printf("left:%d right:%d m:%d mval:%d \n", left,right,m,mval);
		if( mval == target ){
			return m;
		}
		if(mval < target ){
			left = min(int(nums.size()-1),m+1);
		}else if (mval > target ){
			right = m-1 ;
		}
	}

	printf("left:%d nums[left]:%d \n", left, nums[left]);
	if( nums[left] < target){
		return left+1;
	}
	if( nums[left] > target){
		return left;
	}
	return left;
}


    int lengthOfLastWord(string s) {
        if(s.empty()){
            return 0;
        }

        int last = s.size() -1;

        bool firstSpace = false;

		while( last >= 0){
			char c = s[last]; 
			if( c != ' '){
				break;
			}
			last--;
		}
		printf("last:%d \n", last);
		int t = last;//倒数第一个非空格字符
		if( t < 0){
			return 0;
		}

        while (t >= 0){
			char c = s[t];
			if( c == ' '){
				break;
			}
			t--;
        }
        return last - t ;
    }

int main(int argc, char**argv){
    vector<int>  r2Sort;
    srand(Nowms());
    int num = 10;
    if( argc > 1 ){
        num = atoi(argv[1]);
    }
	vector<int>tmp = {1,3};
	//cout << searchInsert(tmp, 4) << endl;
	cout << lengthOfLastWord(" ") << endl;
	cout << lengthOfLastWord("H ") << endl;
	cout << lengthOfLastWord(" H") << endl;
	cout << lengthOfLastWord(" H ") << endl;
	cout << lengthOfLastWord("Hello world") << endl;
    return 0;
}
