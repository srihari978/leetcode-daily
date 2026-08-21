class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
       queue<TreeNode*>q;
       vector<long long>res;
       q.push(root);
       while(!q.empty()){
        int n=q.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            TreeNode * temp=q.front();
            sum+=temp->val;
            q.pop();
            if(temp->left!=nullptr){
                q.push(temp->left);
            }
            if(temp->right!=nullptr){
                q.push(temp->right);
            }
        }
        res.push_back(sum);
       }
       if(res.size()<k)return -1;
       sort(res.begin(),res.end());
       return res[res.size()-k];
    }
};