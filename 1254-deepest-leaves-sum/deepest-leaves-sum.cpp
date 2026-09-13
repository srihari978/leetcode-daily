class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while (!q.empty()) {
            int n = q.size();

            sum = 0;
            for (int i = 0; i < n; i++) {
                auto temp = q.front();
                q.pop();
                sum += temp->val;
                if (temp->left != nullptr)
                    q.push(temp->left);
                if (temp->right != nullptr)
                    q.push(temp->right);
            }
        }
        return sum;
    }
};