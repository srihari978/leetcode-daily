class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root==nullptr) return{};
        vector<int>answer;
       queue<TreeNode*>q;
       q.push(root); 
       while(!q.empty()){
        int size=q.size();
        int levelwisemax=INT_MIN;
        for(int i=0;i<size;i++){
            TreeNode* temp=q.front();
            q.pop();
            levelwisemax=max(temp->val,levelwisemax);
            if(temp->left!=nullptr){
                q.push(temp->left);
            }
            if(temp->right!=nullptr){
                q.push(temp->right);
            }
        }
       answer.push_back(levelwisemax); 
       }
       return answer;
    }
};