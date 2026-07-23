class Solution {
    vector<vector<int>>ans;
    private:
    void solve(TreeNode* root,vector<int>&path){
        if(root==nullptr) return;
        path.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr){
            ans.push_back(path);
        }
        solve(root->left,path);
        solve(root->right,path);
        path.pop_back();
    }
public:
    int sumNumbers(TreeNode* root) {
        vector<int>path;
        solve(root,path);
        string s = "";
        int sum=0;
        for(int i=0;i<ans.size();i++){
            s="";
        for (int num : ans[i]) {
             s += to_string(num);
        }
        sum=sum+stoi(s);
        }
        return sum;
    }
};