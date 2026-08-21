/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void solve(TreeNode* root,vector<int>&temp){
        if(root==nullptr) return;
       solve(root->left,temp);
       temp.push_back(root->val);
       solve(root->right,temp);
    }
    int i=0;
    void solve1(TreeNode* root,vector<int>&temp){
        if(root==nullptr) return;
        solve1(root->left,temp);
         root->val=temp[i++];
       solve1(root->right,temp);

    }
public:
    void recoverTree(TreeNode* root) {
        vector<int>temp;
        solve(root,temp);
        sort(temp.begin(),temp.end());
        solve1(root,temp);
        
    }
};