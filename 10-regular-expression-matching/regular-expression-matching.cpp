class Solution {
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp) {

        // Base Case 1
        if (i == s.size() && j == p.size())
            return true;

        // Base Case 2
        if (j == p.size())
            return false;

        // Base Case 3
        if (i == s.size()) {
            while (j + 1 < p.size() && p[j + 1] == '*')
                j += 2;
            return j == p.size();
        }

        // Memoization
        if (dp[i][j] != -1)
            return dp[i][j];

        // Current characters match?
        bool firstMatch = (s[i] == p[j] || p[j] == '.');

        // Handle x*
        if (j + 1 < p.size() && p[j + 1] == '*') {

            bool skip = solve(i, j + 2, s, p, dp);

            bool take = false;
            if (firstMatch)
                take = solve(i + 1, j, s, p, dp);

            return dp[i][j] = skip || take;
        }

        // Normal character or '.'
        if (firstMatch)
            return dp[i][j] = solve(i + 1, j + 1, s, p, dp);

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 1,
                               vector<int>(p.size() + 1, -1));

        return solve(0, 0, s, p, dp);
    }
};