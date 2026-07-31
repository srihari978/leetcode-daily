class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        if (root == nullptr)
    return 0;
        unordered_map<TreeNode*,TreeNode*>parent;
        TreeNode* startValue = nullptr;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode*temp=q.front();
                q.pop();
                if( temp -> val == start) {
                     startValue = temp ;
                }
                if(temp->left!=nullptr){
                    q.push(temp->left);
                     parent[temp->left] = temp;
                }
                if(temp->right!=nullptr){
                    q.push(temp->right);
                    parent[temp->right] = temp;
                }
            }
        }
      while(!q.empty()){
        q.pop();
      }
      int time=0;
      unordered_set<TreeNode*> visted;
      visted.insert(startValue);
      q.push(startValue);
      while(!q.empty()){
           int n=q.size();
           for(int i=0;i<n;i++){
           TreeNode* temp=q.front();
           q.pop();
           if(temp->left!=nullptr && visted.find(temp->left)==visted.end()){
            visted.insert(temp->left);
            q.push(temp->left);
           }
           if(temp->right!=nullptr && visted.find(temp->right)==visted.end()){
            visted.insert(temp->right);
            q.push(temp->right);
           }
           if(parent.count(temp)&& visted.find(parent[temp])==visted.end()){
            visted.insert(parent[temp]);
            q.push(parent[temp]);
           }
           
           }
           if(!q.empty()) {
            time++;
           }
      }
     return time;
    }
};