class Solution {
    vector<string>list;
    void function(TreeNode* root,vector<string>&path){
        if(root==nullptr) return ;
       path.push_back(to_string(root->val));
        if(root->left==nullptr && root->right==nullptr){
            string s = "";

            for (int i = 0; i < path.size(); i++) {
                s += path[i];
                if (i != path.size() - 1)
                    s += "->";
            }
            list.push_back(s);;
        }
        function(root->left,path);
        function(root->right,path);
        path.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>path;
        function(root,path);
        return list;
        
    }
};