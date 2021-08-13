#include <stdio.h> 
#include <string>  
#include <iostream>  
#include <vector>  
#include <iomanip>
#include <memory>
#include <sys/time.h>
#include "../base.h"
using namespace std;


void reverse(vector<int>& in, int begin, int end){
	while( begin < end){
		std::swap(in[begin], in[end]);
		begin++;
		end--;
	}
}

int search(vector<int>& in, int val){
	int low = 0;
	int high = in.size() -1;
	while( low <= high){
		int mid = low + (high -low)/2;
		if( in[mid] == val){
			return mid;
		}else if(in[mid] > in[high] ){ //说明左半段有序
			if( in[low] <= val && in[mid] > val){
				//说明可能在这里面
				high = mid -1;
			}else{
				low = mid +1; //左边没有，在右边找吧你
			}
		}else{
			if( in[mid] < val && in[high] >= val ){
				low = mid +1;
			}else{
				high = mid -1;
			}
		}
	}
	return -1;
}

int findMin(vector<int>& nums) {
        if(nums.empty()){
            return -1;
        }
        int low = 0;
        int high = nums.size() -1;

        while( low <= high){
            int mid = low + (high-low)/2;
			printf("mid:%d low:%d high:%d \n", mid, low, high);

            if( nums[mid] > nums[high]){
                low = mid+1;
            }else if( nums[mid] < nums[high]){
                high = mid;
            }else{
                high--;
            }
        }
        return nums[low];
    }

int main(int argc, char**argv){
    vector<int>  r2Sort;
    srand(Nowms());
    int num = 13;
    if( argc > 1 ){
        num = atoi(argv[1]);
    }
	vector<int> t = {3,3,3,1};
	cout << findMin(t) << endl;
    return 0;
}
