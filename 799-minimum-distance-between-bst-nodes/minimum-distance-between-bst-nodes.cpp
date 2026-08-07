class Solution {
     int mini = INT_MAX;
    private:
    void solve(TreeNode* root,int &prev){
        if(root==nullptr) return ;
        solve(root->left,prev);
        if(prev!=-1) {mini=min(mini,root->val-prev);}
        prev=root->val;
        solve(root->right,prev);
    }

public:
    int minDiffInBST(TreeNode* root) {
     int prev=-1;
     solve(root,prev);
     return mini;
    }
};