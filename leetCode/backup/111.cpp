https://leetcode.com/problems/minimum-depth-of-binary-tree/submissions/


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
    int minDepth(TreeNode* root) {
        if( root == nullptr){
            return 0;
        }

        if( root->left == nullptr && root->right == nullptr){
            return 1;
        }

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if( left == 0){
            return right +1;
        }
        if( right == 0 ){
            return left +1;
        }
        return std::min(left,right) + 1 ;

    }
};
