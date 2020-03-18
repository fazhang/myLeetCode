https://leetcode.com/problems/kth-smallest-element-in-a-bst/

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if( root == nullptr){
            return 0;//error?
        }
        while(true){
            while(root != nullptr){
                needStack.push(root);
                root = root->left;
            }//一直取到最左节点
            
            root = needStack.top();
            needStack.pop();
            if( --k == 0){
                return root->val;
            }
            root = root->right;
        }
        
    }
    
    public:
    stack<TreeNode*> needStack;
    
};
