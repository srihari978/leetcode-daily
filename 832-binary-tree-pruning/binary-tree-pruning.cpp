class Solution {
private:
    TreeNode* solve(TreeNode* root) {
        if (root == nullptr)
            return nullptr;

        // First prune left and right subtrees
        root->left = solve(root->left);
        root->right = solve(root->right);

        // If current node is 0 and has no children,
        // it does not contain any 1 in its subtree
        if (root->val == 0 &&
            root->left == nullptr &&
            root->right == nullptr) {
            return nullptr;
        }

        return root;
    }

public:
    TreeNode* pruneTree(TreeNode* root) {
        return solve(root);
    }
};