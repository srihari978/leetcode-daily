class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr;
        queue<TreeNode*> q;
        q.push(root);
        int k = 0;
        while (!q.empty()) {
            int n = q.size();
            vector<TreeNode*> currentLevel;
            for (int i = 0; i < n; i++) {
                auto temp = q.front();
                q.pop();
                // Collect nodes on odd levels to reverse their values
                if (k % 2 == 1) {
                    currentLevel.push_back(temp);
                }
                if (temp->left != nullptr)
                    q.push(temp->left);
                if (temp->right != nullptr)
                    q.push(temp->right);
            }

            // Reverse values from both ends across the entire row
            if (k % 2 == 1) {
                int left = 0, right = currentLevel.size() - 1;
                while (left < right) {
                    swap(currentLevel[left]->val, currentLevel[right]->val);
                    left++;
                    right--;
                }
            }

            k++;
        }
        return root;
    }
};