class Solution {
    map<tuple<int, int, int>, int> mp;
    map<int, int> freq;
    
    int id = 1;
    
    vector<TreeNode*> ans;

    int solve(TreeNode* root) {
        
        // Step 1: Base case
        if (root == nullptr)
            return 0;

        // Step 2: Get left subtree ID
        int leftID = solve(root->left);

        // Step 3: Get right subtree ID
        int rightID = solve(root->right);

        // Step 4: Create current subtree signature
        auto curr = make_tuple(root->val, leftID, rightID);

        // Step 5: If this subtree already exists
        if (mp.find(curr) != mp.end()) {
            int currID = mp[curr];
            freq[currID]++;
            if (freq[currID] == 2) {
                ans.push_back(root);
            }

            return currID;
        }
        int currID = id++;

        mp[curr] = currID;
        freq[currID] = 1;
        return currID;
    }

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

        solve(root);

        return ans;
    }
};