https://leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //不要大量移动，那直接用反向查找的办法
        // 左指针查找val  右指针查找!val
        // 把右填充到左

        if( nums.empty()){
            return 0;
        }

        int left = 0 ;
        int right = nums.size() -1 ;

        while(left <= right){
            int lval = nums[left];
            if( lval != val){
                left++;
                continue;
            }

            int rval = nums[right];
            if(rval == val){
                right--;
                continue;
            }
            nums[left] = rval;
            left++;
            right--;
        }
        return  left;

    }
};
