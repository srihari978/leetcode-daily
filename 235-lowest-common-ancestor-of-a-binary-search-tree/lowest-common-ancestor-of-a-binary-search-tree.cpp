class Solution {
    private:
    bool helper(TreeNode* root,TreeNode* p,vector<TreeNode*>&path){
        if(root==nullptr){
            return false;
        }
       path.push_back(root); 
       if(root==p){
        return true;
       }
       if(helper(root->left,p,path)) return true;
      if(helper(root->right,p,path)) return true;
       path.pop_back();
       return false;

    }   
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     vector<TreeNode*>pathP;
    //     vector<TreeNode*>pathQ;
    //     helper(root,p,pathP);
    //     helper(root,q,pathQ);
    //     TreeNode* ans=nullptr;
    //     int n=min(pathP.size(),pathQ.size());
    //     for(int i=0;i<n;i++){
    //         if(pathP[i]==pathQ[i]) ans=pathP[i];
    //         else break;
    //     }
    //   return ans;  
    while(root!=nullptr){
        if(p->val < root->val && q->val < root->val){
            root=root->left;
        }
        else if(p->val>root->val && q->val > root->val){
            root=root->right;
        }
        else return root;
    }
    return nullptr;
    }
};