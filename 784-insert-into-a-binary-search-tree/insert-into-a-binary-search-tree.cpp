class Solution {
    TreeNode* solve(TreeNode* root,int val){
        if(root == nullptr){
            return new TreeNode(val);
        }
        if(root->val<val){
           root->right= solve(root->right,val);
        }
        else{
           root->left= solve(root->left,val);
        }
        return root;
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
         return solve(root,val);
    }
};