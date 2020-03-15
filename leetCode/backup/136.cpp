https://leetcode.com/problems/single-number/
//这个还有各种变种，按位取多个奇数个的数

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if( nums.empty()){
            return 0;
        }
        int ret = nums[0];
        for( int i = 1; i < nums.size(); i++){
            ret ^= nums[i];
        }
        return ret;
    }
};
