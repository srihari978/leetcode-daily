class Solution {
    TreeNode* prev=nullptr;
    private:
    void preorder(TreeNode* root){
        if(root==nullptr)return ;
        TreeNode* left=root->left;
        TreeNode* right=root->right;
       if(prev!=nullptr){
        prev->left=nullptr;
        prev->right=root;

       }
       prev=root;
        preorder(left);
        preorder(right);
    }
public:
    void flatten(TreeNode* root) {
        if(root==nullptr) return ;
        // vector<TreeNode*>nodes;
        preorder(root);
        // for(int i=0;i<nodes.size()-1;i++){
        //     nodes[i]->left=nullptr;
        //     nodes[i]->right=nodes[i+1];
        // }
        // nodes.back()->left=nullptr;
        // nodes.back()->right=nullptr;
        
    }
};