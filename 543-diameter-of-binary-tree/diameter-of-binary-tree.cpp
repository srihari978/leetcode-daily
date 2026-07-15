class Solution {
    private:
    int ans = 0;
    int traverse(TreeNode* root){
        if(root==nullptr) return 0;
      int left=traverse(root->left);
      int right=traverse(root->right);
        ans = max(ans, left + right); 
      return 1 + max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
       traverse(root); 
       return ans;
    }
};