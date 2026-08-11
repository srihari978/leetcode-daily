class Solution {
    private:
    TreeNode* solve(TreeNode* root,int target){
        if(root==nullptr)return nullptr;
        root->left=solve(root->left,target);
        root->right=solve(root->right,target);
        if(root->val==target && root->left==nullptr && root->right==nullptr) return nullptr;
        return root;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
      return solve(root,target);
    }
};