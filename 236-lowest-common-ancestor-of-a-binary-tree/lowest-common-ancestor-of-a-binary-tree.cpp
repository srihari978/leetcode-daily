class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // Base case
        if (root == NULL)
            return NULL;

        // If current node is one of the targets
        if (root == p || root == q)
            return root;

        // Search left subtree
        TreeNode* left = lowestCommonAncestor(root->left, p, q);

        // Search right subtree
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both sides found a target,
        // current node is the LCA
        if (left != NULL && right != NULL)
            return root;

        // Otherwise return whichever side found a target
        if (left != NULL)
            return left;

        return right;
    }
};