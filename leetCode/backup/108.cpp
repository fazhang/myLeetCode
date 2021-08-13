https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        return buildBST(nums, 0, nums.size() -1 );
    }

    TreeNode* buildBST(vector<int>& nums, int begin, int end){
        if( begin <= end){
            int mid = begin + (end - begin)/2;
            TreeNode* t = new TreeNode(nums[mid]);
            t->left = buildBST(nums, begin, mid-1);
            t->right = buildBST(nums, mid+1, end);
            return t;
        }

            return nullptr;
    }
};
