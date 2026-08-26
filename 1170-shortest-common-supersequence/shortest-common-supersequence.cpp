class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        string ans = "";
        int i = 0;
        int j = 0;
        while (i < n && j < m) {
            if (s1[i] == s2[j]) {
                ans += s1[i];
                i++;
                j++;
            } else if (dp[i + 1][j] >= dp[i][j + 1]) {
                ans += s1[i];
                i++;
            } else {
                ans += s2[j];
                j++;
            }
        }
        while (i < n)
            ans += s1[i++];
        while (j < m)
            ans += s2[j++];
        return ans;
    }
};