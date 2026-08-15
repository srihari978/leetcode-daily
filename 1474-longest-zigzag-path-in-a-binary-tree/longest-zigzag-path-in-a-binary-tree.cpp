class Solution {
    int ans = 0;

    void solve(TreeNode* root, int left, int right) {
        if (root == nullptr)
            return;

        ans = max(ans, max(left, right));

        // Go LEFT
        solve(root->left, right + 1, 0);

        // Go RIGHT
        solve(root->right, 0, left + 1);
    }

public:
    int longestZigZag(TreeNode* root) {
        solve(root, 0, 0);
        return ans;
    }
};