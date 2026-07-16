class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>s;
         if (root == nullptr)
            return s;
         queue<TreeNode*>q;
          q.push(root);
        while(!q.empty()){
            vector<int>store;
            int n=q.size(); 
            for(int i=0;i<n;i++){
               TreeNode*  temp=q.front();
                 q.pop();
                 store.push_back(temp->val);
                 if(temp->left!=nullptr){
                    q.push(temp->left);
                    }
                   if(temp->right!=nullptr){
                    q.push(temp->right);
                 }        
            }
            s.push_back(store);
        }
        for(int i=0;i<s.size();i++){
            if(i%2!=0){
                reverse(s[i].begin(), s[i].end());
            }
    }
        return s;
    }
};