class Solution {
    int count=0;
    void t(TreeNode* root,int low,int high){
        if(root==nullptr)return ;
        t(root->left,low,high);
        if(low<root->val && root->val<high){
            count+=root->val;
        }
         t(root->right,low,high);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        t(root,low,high);
        return count+low+high;
    }
};