class Solution {
    private:
    bool solve(TreeNode* root,int sum){
        if(root==nullptr) return false;
       if (root->left == nullptr && root->right == nullptr)
            return sum == root->val;
       bool left= solve(root->left,sum-root->val);
        bool right=solve(root->right,sum-root->val);
        return left||right;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,targetSum);
    }
};