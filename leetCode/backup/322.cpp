https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount <= 0 ){
            return 0;
        }
        //动态规划题
        //可以用二维，也可以用一维
        // dp[i][j] 表示第i个coin 组成 j 这么大的total时
        //最少的个数
        //dp[i][j] = std::min(dp[i][j-1] , dp[i-1][j - coins[i]] + 1 )
        // 这里肯定还要考虑负数的问题
        // dp[i] = std::min(dp[i], dp[i - coins[j] ] + 1 )

        vector<int> dp(amount+1,amount+1);
        //int minAmount = amount+1;
        dp[0] = 0;
        //[0,amount]  =>  每个初始化为'amount+1'
        //因为不可能为amount+1，所以如果最后的结果是这个值
        //则说明没找到有效解，返回-1

        for( int i = 1  ; i <= amount; i++){
            for( int j = 0 ; j < coins.size(); j++){
                int tmpcoin = coins[j];
                if( tmpcoin <= i ){
                    dp[i] = std::min(dp[i], dp[i-tmpcoin] +1);
                }
            }
        }

        int minAmount = dp[amount];
        if( minAmount == amount+1){
            return -1;
        }
        return minAmount;
    }
};
