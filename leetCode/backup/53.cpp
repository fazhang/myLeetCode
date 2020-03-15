https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //dp[i] = 以i 结尾的最大max
        if( nums.size() == 0 ){
            return 0;
        }
        int maxSum = nums[0];//只有一个值
        vector<int> dp(nums.size());

        dp[0] = nums[0];
        int lastIndex = 0;
        int lastSum = nums[0];

        for( int i = 1; i < nums.size(); i++){
            int sum = dp[i-1]  + nums[i];
            if( sum >= nums[i]){
                dp[i] = sum;
            }else{
                dp[i] = nums[i];
                lastIndex = i;
            }

            if( dp[i] >= maxSum){
                maxSum = dp[i];
            }
        }
        return maxSum;
    }
};

