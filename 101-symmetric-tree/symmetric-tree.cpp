class Solution {
    private:
    bool solve(TreeNode* root1,TreeNode* root2){
        if(root1==nullptr && root2==nullptr) return true;
        if(root1==nullptr || root2==nullptr) return false;
        if(root1->val!=root2->val) return false;
        return solve(root1->left,root2->right) && solve(root1->right,root2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return solve(root,root);
        
    }
};