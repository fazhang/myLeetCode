https://leetcode.com/problems/search-insert-position/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        if( nums.empty()){
            return 0;
        }
        //有点二分查找的意思。。。
        int left = 0 ;
        int right = nums.size()-1;
        while(left < right && left < nums.size() && right > 0 ){
            int m = (left + right +1 )/2;
            int mval = nums[m];
            if( mval == target ){
                return m;
            }
            if(mval < target ){
                left = min((int)(nums.size() -1),m+1);
            }else if (mval > target ){
                right = m-1 ;
            }
        }

            if( nums[left] < target){
                return left+1;
            }
            if( nums[left] > target){
                return left;
            }
        return left;
    }
};
