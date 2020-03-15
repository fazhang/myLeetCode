https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int lastIndex = 1;
        for( int i = 1 ; i < nums.size(); i++){
            int val = nums[i];
            int lastval = nums[i-1];
            if( val ==  lastval){
                continue;
            }
            nums[lastIndex++]=val;
        }
        return lastIndex;
    }
};
