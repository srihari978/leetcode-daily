class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>nodes;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto curr = q.front();
                q.pop();
                TreeNode* temp=curr.first;
                int x=curr.second.first;
                int y=curr.second.second;
                nodes[y][x].insert(temp->val);
                if(temp->left!=nullptr){
                    q.push({temp->left,{x+11,y-1}});
                }
                if(temp->right!=nullptr){
                    q.push({temp->right,{x+1,y+1}});
                }

            }
        }
        vector<vector<int>> ans;
         for (auto &col : nodes) {
               vector<int> temp;
              for (auto &row : col.second) {
              for (auto &value : row.second) {
                   temp.push_back(value);
            }
             }
        ans.push_back(temp);
       }
      return ans;
        
    }
};