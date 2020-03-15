https://leetcode.com/problems/binary-tree-level-order-traversal-ii/


class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if( root == NULL){
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
            result.insert(result.begin(), tmp);
            std::swap(l1Queue,l2Queue);
        }
        return result;
    }



};
