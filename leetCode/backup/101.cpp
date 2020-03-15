https://leetcode.com/problems/symmetric-tree/

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
    
    bool isSymmetric_Second(TreeNode* p1, TreeNode* p2){
        if( p1 == NULL && p2 == NULL){
            return true;
        }
        if( p1 == NULL && p2 != NULL){
            return false;
        }
         if( p1 != NULL && p2 == NULL){
            return false;
        }
        if(p1->val != p2->val ){
            return false;
        }
        return isSymmetric_Second(p1->left, p2->right) && isSymmetric_Second(p1->right, p2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return isSymmetric_Second(root->left, root->right);
    }
};
