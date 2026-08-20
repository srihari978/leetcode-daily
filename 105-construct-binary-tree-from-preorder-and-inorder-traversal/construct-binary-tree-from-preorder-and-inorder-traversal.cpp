
class Solution {
      TreeNode* buildtree(vector<int>&inorder,int instart,int inend,vector<int>&preorder,int prestart, int preend,map<int,int>&imap){
        if(prestart>preend || instart>inend){
            return NULL;
        }
        TreeNode* root= new TreeNode(preorder[prestart]);
        int inroot=imap[root->val];
        int numsleft=inroot-instart;
        root->left=buildtree(inorder,instart,inroot-1,preorder,prestart+1,prestart+numsleft,imap);
        root->right=buildtree(inorder,inroot+1,inend,preorder,prestart+numsleft+1,preend,imap);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         map<int,int>imap;
        for(int i=0;i<inorder.size();i++){
            imap[inorder[i]]=i;
        }
        TreeNode* root=buildtree(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,imap);
        return root;
    }
};