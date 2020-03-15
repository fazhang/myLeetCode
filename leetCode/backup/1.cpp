https://leetcode.com/problems/two-sum/


static auto _=[]()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
                        vector<int> nums_minus;
            set<int>  allnums;
            map<int,int> num2index;
            vector<int> t ;
            nums_minus.reserve(nums.size());
            for( size_t i = 0 ; i < nums.size(); i ++){
               
                nums_minus[i] = target - nums[i];
                if( num2index.find(nums_minus[i]) != num2index.end()){
                    t.push_back(num2index[nums_minus[i]]);
                    t.push_back(i);
                    break;
                }
                //allnums.insert(nums[i]);
                 num2index[ nums[i]] = i;
            }
            //查找nums_minus对应的元素的index 是否相同，如果相同则有问题
            
            return t;
    }
};
