class Solution {
public:
    int minDepth(TreeNode* root) {  
        if(root==nullptr) return{};
       int z=1;
       queue<TreeNode*>q;
       q.push(root); 
       while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode* temp=q.front();
            q.pop();
            if (temp->left == nullptr && temp->right == nullptr)
                return z;
            if(temp->left!=nullptr){
                q.push(temp->left);
            }
            if(temp->right!=nullptr){
                q.push(temp->right);
            }
        }
        z++;
    
       }
        return 0;
    }
};