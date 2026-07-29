class Solution {
    void reverseinorder(TreeNode* root,int &sum){
        if(root==nullptr) return ;
        reverseinorder(root -> right,sum);
        sum+=root->val;
        root->val = sum;
        reverseinorder(root -> left,sum);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
       reverseinorder(root,sum);
       return root;
    }
};