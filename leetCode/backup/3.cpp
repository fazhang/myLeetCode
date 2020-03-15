https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //最长不重复子串。 一维动态规划
        //dp 的定义是， 以当前item 结尾的最长不重复串是多长
        int strLen = s.size();
        vector<int> dp(strLen,1);//至少是1

        //需要一个辅助数组，记录某个字符，最后一次出现的位置
        vector<int> charLastIndex(256,-1);

        int start = 0 ;
        int maxLen = 0 ;

        for( int i = 0 ; i < strLen ; i++){
            char x = s.at(i);
            int lastIndex = charLastIndex[int(x)];//这个字符出现的最后一次的位置
            if( lastIndex != -1){
                start = std::max(lastIndex+1, start);
            }
            charLastIndex[x] = i;
            dp[i] = i - start +1 ;
            if(dp[i] > maxLen){
                maxLen = dp[i];
            }
        }
        return maxLen;
    }
};
