    class Solution {
    public:
        TreeNode* invertTree(TreeNode* root) {
             if (root == nullptr)
            return nullptr;
            queue<TreeNode*>q;
            q.push(root);
            while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            swap(temp->left, temp->right);
                if(temp->right!=nullptr){
                q.push(temp->right);
                }
                if(temp->left!=nullptr){
                q.push(temp->left);
                }    
            }
            return root;  
        }
    };