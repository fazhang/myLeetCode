https://leetcode.com/problems/permutations/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        if( nums.size() < 2){
            res.push_back(nums);
            return res;
        }
        std::sort(nums.begin(), nums.end());
        bool bFind = true;
        while (bFind){
            res.push_back(nums);
            bFind = next(nums);
        }
        return res;
    }

    bool  next(vector<int>& nums){
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
        return bFind;

    }
};
