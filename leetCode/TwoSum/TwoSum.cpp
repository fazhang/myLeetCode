#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

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
                if( allnums.find(nums_minus[i]) != allnums.end()){
                    t.push_back(num2index[nums_minus[i]]);
                    t.push_back(i);
                    //t.push_back(nums_minus[i]);
                    //t.push_back(nums[i]);
                    break;
                }
                allnums.insert(nums[i]);
                num2index[ nums[i]] = i;
            }
            //查找nums_minus对应的元素的index 是否相同，如果相同则有问题
            
            return t;
        }
};


int main(int argc, char**argv){
    //vector<int> nums = {2,7, 11,15};
    vector<int> nums = {9,9};
    int target = 18;
    Solution s;
    vector<int>  t = s.twoSum(nums, target);
    for( auto i : t ){
        cout << i  << endl ;
    }
}
