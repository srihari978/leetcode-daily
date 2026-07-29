class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>s;
         if (root == nullptr)
            return s;
         queue<TreeNode*>q;
          q.push(root);
          bool x=true;

        while(!q.empty()){
             int n=q.size();
            vector<int>store(n);
            
            for(int i=0;i<n;i++){
               TreeNode*  temp=q.front();
                 q.pop();
                 int index=x?i:n-i-1;
                 store[index]=temp->val;
                 if(temp->left!=nullptr){
                    q.push(temp->left);
                    }
                   if(temp->right!=nullptr){
                    q.push(temp->right);
                 }        
            }
        s.push_back(store);
         x=!x;
        }
       
        return s;
    }
};