https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for( auto i : nums){
            total += i;
        }
        if( nums.empty()){
            true;
        }
        if(total&1 != 0 ){
            return false;
        }

        int mSize = nums.size();
        int subSum = total/2;

        int m = mSize +1;
        int n = subSum +1;

        //vector< vector<int> > dp
        //dp[i][j]  表示前i 个元素是否有和为j 的子集
        //dp[i][j] = dp[i-1][j] or dp[i-1][j - nums[i] ];

        bool* dp = new bool[m*n];
        memset(dp, false, m*n-1 );

        for( int i = 0 ; i < m; i++){
            dp[i*n+0] = true;
        }
        for( int j = 0 ; j < n; j++){
            dp[0*m+j] = false;
        }

        for( int i = 1; i < m ; i++){
            for( int j = 1; j < n ;j ++){

                if( j >= nums[i-1]){
                    //不要当前这一个元素，或者要当前这一个元素
                    //这里要特别注意 nums[i-1]  由于 i 属于[1,m]  其中 m = mSize +1 .
                    // 所以要-1 ，否则会越界
                    dp[i*n+j] = dp[(i-1)*n+j] || dp[(i-1)*n+ (j- nums[i-1])];
                }else{
                   dp[i*n+j] = dp[(i-1)*n+j] ;
                }

            }
        }
        bool result = dp[mSize*n + subSum ];
        delete[] dp;
        return result;
    }
};
