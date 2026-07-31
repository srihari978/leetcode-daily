class Solution {
    private:
    bool ValidBST(TreeNode* root,long long low,long long high){
        if(root==nullptr) return true;
        if(root->val<=low || root->val>=high) return false;
        bool left=ValidBST(root->left,low,root->val);
        bool right=ValidBST(root->right,root->val,high);
        return left && right;
    } 
    
public:
    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return true;
      return ValidBST(root, LLONG_MIN, LLONG_MAX);
    }
};