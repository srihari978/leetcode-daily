class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int leafnode=0;
        int sum=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left){ 
                if(temp->left->left==nullptr &&  temp->left->right == nullptr){
                     sum=sum+temp->left->val;
                }
                 q.push(temp->left);
                 }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            
        }
        return sum;
            }
};