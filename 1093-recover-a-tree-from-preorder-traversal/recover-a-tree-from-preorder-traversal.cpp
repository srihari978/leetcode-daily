
class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        int i=0;
        stack<TreeNode*>st;
        TreeNode* root = nullptr;
        while(i<s.size()){
             int depth = 0;
            while (i < s.size() && s[i] == '-') {
                depth++;
                i++;
            }
             int val = 0;
                while (i < s.size() && s[i] != '-') {
                val = val * 10 + (s[i] - '0');
                i++;
                }
           TreeNode* newnode = new TreeNode(val);
             if (depth == 0) {
                root = newnode;
            }
            else{
                while(st.size()>depth){
                    st.pop();
                }   
                TreeNode* parent = st.top();
                if (parent->left == nullptr) {
                    parent->left = newnode;
                }
                else {
                    parent->right = newnode;
                }
            }
            st.push(newnode);
        }
       return root; 
    }
};