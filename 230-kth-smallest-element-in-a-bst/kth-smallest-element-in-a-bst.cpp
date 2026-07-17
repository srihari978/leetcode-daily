class Solution {
    private:
    void helper(TreeNode* root,vector<int>&ans){
        if(root==nullptr) return;
        if(root!=nullptr)   ans.push_back(root->val);
           helper(root->left,ans);
           helper(root->right,ans);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        helper(root,ans);
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};