class Solution {
    private:
    void markparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent){
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left!=nullptr){
                q.push(temp->left);
                parent[temp->left]=temp;
            }
            if(temp->right!=nullptr){
                q.push(temp->right);
                parent[temp->right]=temp;
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (root == nullptr) return {};
         unordered_map<TreeNode*,TreeNode*> parent;
        markparent(root, parent);
        unordered_map<TreeNode*,bool>visted;
        queue<TreeNode*>q;
        q.push(target);
        visted[target]=true;
        int currlevel=0;
        while(!q.empty()){
            int n = q.size();
            if(currlevel==k) break;
           
             for (int i = 0; i < n; i++) {
                 TreeNode* temp=q.front();
            q.pop(); 
            if(temp->left!=nullptr && !visted[temp->left]){
               visted[temp->left]=true;
               q.push(temp->left);
            }
            if(temp->right!=nullptr && !visted[temp->right]){
                visted[temp->right]=true;
                q.push(temp->right);
            }
            if (parent.count(temp) && !visted[parent[temp]]){
                visted[parent[temp]]=true;
                q.push(parent[temp]);
            }


        }
        currlevel++;
        }
        vector<int>result;
        while(!q.empty()){
            TreeNode* current=q.front();
            q.pop();
            result.push_back(current->val);

        }
        return result;
    }
};