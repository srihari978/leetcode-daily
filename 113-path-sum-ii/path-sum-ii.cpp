class Solution {
    vector<vector<int>>list;
    void solve(TreeNode* root,int targetSum,vector<int>&path){
        if(root==nullptr) return ;
        path.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr){
            if(targetSum==root->val)  list.push_back(path);
        }
        solve(root->left,targetSum-root->val,path);
        solve(root->right,targetSum-root->val,path);
        path.pop_back();  
          }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        solve(root,targetSum,path);
     return list;
        
    }
};