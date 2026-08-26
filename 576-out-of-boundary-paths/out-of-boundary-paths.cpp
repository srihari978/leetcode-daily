class Solution {
    const int MOD = 1e9 + 7;

    int solve(int m, int n, int maxMove, int i, int j, int move, vector<vector<vector<int>>>&dp) {

        // Went outside the grid
        if (i < 0 || j < 0 || i >= m || j >= n)
            return 1;

        // Used all allowed moves
        if (move == maxMove) return 0;
        if(dp[i][j][move] != -1) return dp[i][j][move];
        int up = solve(m, n, maxMove, i - 1, j, move + 1,dp);
        int down = solve(m, n, maxMove, i + 1, j, move + 1,dp);
        int left = solve(m, n, maxMove, i, j - 1, move + 1,dp);
        int right = solve(m, n, maxMove, i, j + 1, move + 1,dp);

        return dp[i][j][move]=(up +1LL * down + left + right) % MOD;
    }

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
     vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return solve(m, n, maxMove, startRow, startColumn, 0,dp);
    }
};