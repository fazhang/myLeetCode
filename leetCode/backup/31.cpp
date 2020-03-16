https://leetcode.com/problems/next-permutation/
//全排列会用上这个思路 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        bool bFind = false;
        int len = nums.size();
        for( int i = nums.size() -2; i >= 0 ; i--){
            int x = nums[i];
            if( x < nums[i+1]){
                int right0 = x;
                //rebuild a greater seq   [i,len - 1 ]
                std::sort(nums.begin() + i , nums.end() );
                for( int j = i; j < len; j++){
                    int y = nums[j];
                    if( y > x){
                        while(j > i){
                            std::swap(nums[j], nums[j-1]);
                            j--;
                        }
                        break;
                    }
                }
                bFind = true;
                break;
            }
            
        }
        if( !bFind){
            std::sort(nums.begin(), nums.end());
        }
        //return bFind;
        
    }
};
