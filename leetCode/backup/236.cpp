https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = nullptr;
        recurseTree(root,p,q);
        return ans;
    }
    
    bool recurseTree(TreeNode*  cur, TreeNode* p , TreeNode* q){
        if( cur == nullptr){
            return false;
        }
        
        bool bleft = recurseTree(cur->left, p , q);
        if( ans != nullptr){
            return true;
        }//这一句可以防止后面多递归了右子树
        bool bright = recurseTree(cur->right, p , q);
        
        bool mid = ( cur == q || cur ==p);
        
        if( mid + bleft + bright >= 2  ){
            ans = cur;
        }
        return (mid||bleft||bright);
    }
    TreeNode* ans;
    
};
