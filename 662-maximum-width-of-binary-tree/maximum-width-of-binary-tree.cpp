class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<pair<TreeNode*,long long >>q;
        long long ans = 0;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
             long long minIndex = q.front().second;
            long long first = 0, last = 0;
             for(int i=0;i<n;i++){
               
                auto it=q.front();
                TreeNode* temp=it.first;
                long long  index=it.second-minIndex;
                q.pop();
                 if (i == 0)
                    first = index;

                if (i == n - 1)
                    last = index;
                if(temp->left!=nullptr){
                    long long left=2*index+1;
                    q.push({temp->left,left});
                }
                if(temp->right!=nullptr){
                    long long  right=2*index+2;
                    q.push({temp->right,right});
                }
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};