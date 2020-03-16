https://leetcode.com/problems/edit-distance/


class Solution {
public:
    
    
    int minDistance(string word1, string word2) {
        //动态规划的问题 编辑距离
        
       int  iLen = word1.size();
       int  jLen = word2.size();
        
        vector< vector<int> > dp(iLen+1);
        for( int i = 0 ; i < iLen+1; i++){
            dp[i].resize(jLen+1);
        }
        for(int i = 0 ; i < iLen +1; i++ ){
            dp[i][0] = i ; 
        }
        for(int j = 0 ; j < jLen +1; j++ ){
            dp[0][j] = j ; 
        }
        
        for( int i = 1 ; i < iLen+1; i++){
            for( int j = 1 ; j < jLen+1 ;j++){
                char x = word1[i-1];
                char y = word2[j-1];
                if( x == y){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i-1][j]+1, min(dp[i][j-1]+1, dp[i-1][j-1]+1));
                }
            }
        }
        
        return dp[iLen][jLen];
    }
    
    
};
