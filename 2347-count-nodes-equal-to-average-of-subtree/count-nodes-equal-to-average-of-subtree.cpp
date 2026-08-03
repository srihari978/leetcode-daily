class Solution {
    int count=0;
    private:
    pair<int,int>function(TreeNode* root){
        if(root==nullptr){
            return{0,0};
        }
        auto left=function(root->left);
        auto right=function(root->right);
        int sum=left.first+right.first+root->val;
        int node=left.second+right.second+1;
        if(sum/node==root->val){
           count++;
        }
        return {sum,node};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        function(root);
        return count;
    }
};