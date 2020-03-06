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

class Solution {
	public:
		int findTargetSumWays(vector<int>& nums, int S) {
			//传入的都是非0数，  +号则无影响  -号则为相反
			// +号收集为一个小集合Sum(A)  -号收集为小集合 Sum(B)
			// 则 Sum(A) - Sum(B) = S
			// 而 Sum(A)  + Sum(B)  =sum(nums)
			// 又 S+sum(nums) 是固定值
			// 则类似于 https://leetcode.com/problems/partition-equal-subset-sum/  求 nums 中， 是否有子集合 满足 (S+sum(nums))/2

			int ret = 0 ;
			int total = 0 ;
			if( nums.empty() && S == 0 ){
				return 1;
			}
			for( auto i : nums){
				total += i;
			}
			if( S > total){
				return 0;
			}
			int target = total+S;
			if(target & 1 != 0){
				return 0;//无解
			}
			target /= 2;

			//用二维数组的动态规划来解
			//dp[i][j] 是前 i 个数组成 j 这个数的子集合个数
			//要么不选nums[i]  则
			//nums[i-1]  这里要特别注意， 前i 个 是i-1
			//dp[i][j] = dp[i-1][j] + dp[i-1][j- nums[i-1]]

			int iNum = nums.size() +1;
			int jNum = target +1;

			int* dp = new int[  jNum ];
			memset(dp, 0 , (jNum)*sizeof(int) );


			//初始化 0行 0 列
			dp[0] = 1;


			for( int i = 1; i < iNum ; i++){
				int num = nums[i-1];
				cout << "================= num " << num  << endl;
				for( int j = target ; j >= num; j--){
					dp[j] = dp[j] + dp[j - num];
					output(dp, jNum);
				}
				cout << "=================" << endl;
					output(dp, jNum);
				/*
				for( int j = 0 ; j < jNum; j++){
					if( j >= num){
						dp[ i*jNum + j ] = dp[(i-1)*jNum + j] + dp[(i-1)*jNum + (j - num)];
					}else{
						dp[ i*jNum + j ] = dp[(i-1)*jNum + j] ;
					}
				}
				*/
			}

			int res = dp[jNum-1];
			delete[] dp ;
			return res;
		}

		void output(int* dp , int size){
			for( int i = 0 ; i < size;i++){
				cout << dp[i] << " " ;
			}
			cout << endl;
		}
};

int main(int argc, char**argv){
    vector<int>  r2Sort;
    srand(Nowms());
    int num = 9;
    if( argc > 1 ){
        num = atoi(argv[1]);
    }
	cout <<   199999%17 << endl;
	cout <<   19999%17 << endl;
	cout <<   (19999LL*199999)%17 << endl;
	vector<int>  nums={1,2,3};
	Solution s ;
	cout << "findTargetSumWays " << s.findTargetSumWays(nums, num) << endl;
    return 0;
}
