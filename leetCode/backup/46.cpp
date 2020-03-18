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


//添加一个DFS的办法

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        //这里试试用dfs 来做

        vector<vector<int> > ans;//返回结果
        if( nums.empty()){
            return ans;
        }
        if( nums.size() == 2){
            ans.push_back({nums[0], nums[1]});
            ans.push_back({nums[1], nums[0]});
            return ans;
        }
        if( nums.size() == 1){
            ans.push_back(nums);
            return ans;
        }
        for(int i = 0 ; i < nums.size(); i++){
            int x = nums[i];
            vector<int> tmp = nums;
            tmp.erase(tmp.begin() + i);
            vector<vector<int> > ret = permute(tmp);
            for( auto s: ret){
                s.insert(s.begin(),x);
                ans.push_back( s);
            }
        }
        return ans;
    }

};
