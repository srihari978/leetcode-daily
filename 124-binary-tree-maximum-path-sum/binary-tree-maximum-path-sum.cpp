class Solution {
    private:
    int ans=INT_MIN;;
    int traverse(TreeNode* root){
        if(root==nullptr)return 0; 
      int   left = max(0, traverse(root->left));
        int right = max(0, traverse(root->right));
        ans=max(ans,left+right+root->val);
        return root->val+max(left,right);
    }
public:
    int maxPathSum(TreeNode* root) {
        
        traverse( root);
        return ans;
    }
};