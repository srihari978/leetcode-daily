class Solution {
    int cam=0;
    int solve(TreeNode* root){
        if(root==nullptr) return 2;
        int left=solve(root->left);
        int right=solve(root->right);
        if(left==0 || right == 0){
            cam++;
            return 1;
        }
        if(left==1 || right==1) return 2;
        return 0;
    }
public:
    int minCameraCover(TreeNode* root) {
          if(root == nullptr)
            return 0;

        if(solve(root) == 0)
            cam++;
        return cam;
        
    }
};