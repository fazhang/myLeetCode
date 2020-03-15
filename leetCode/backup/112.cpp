https://leetcode.com/problems/path-sum/


class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr){
            return false;
        }
        int needval = sum - root->val;
        if( needval == 0 && root->left == nullptr && root->right == nullptr){
            return true;
        }

        return hasPathSum(root->left, needval) || hasPathSum(root->right, needval);
    }
    //用递归解？
};
