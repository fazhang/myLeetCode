https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > result;
        if(root == NULL){
            return result;
        }

        std::queue<TreeNode*>  l1Queue;
        l1Queue.push(root);
        while(!l1Queue.empty())
        {
            std::queue<TreeNode*>  l2Queue;
            vector<int> tmp;
            while( !l1Queue.empty()){
                TreeNode* node = (l1Queue.front());
                l1Queue.pop();
                tmp.push_back(node->val);
                if(node->left != NULL){
                     l2Queue.push(node->left);
                }
                if(node->right != NULL){
                     l2Queue.push(node->right);
                }
            }
            result.insert(result.end(), tmp);
            std::swap(l1Queue,l2Queue);
        }
        return result;
    }

};
