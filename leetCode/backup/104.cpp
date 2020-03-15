https://leetcode.com/problems/maximum-depth-of-binary-tree/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int len = 0 ;
        if( root == NULL){
            return len;
        }
        len ++;
        return len + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};
