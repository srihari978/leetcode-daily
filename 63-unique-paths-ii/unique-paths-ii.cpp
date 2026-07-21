class Solution {
    //   int helper(vector<vector<int>> &grid, int i, int j, int n, int m,vector<vector<int>>&dp) {
    //     if (i >= n || j >= m || grid[i][j] == 1)
    //         return 0;
    //     if (i == n - 1 && j == m - 1)
    //         return 1;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int down = helper(grid, i + 1, j, n, m,dp);
    //     int right = helper(grid, i, j + 1, n, m,dp);
    //     return dp[i][j]=down + right;
    //}
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]==1) return 0;

        vector<vector<int>>dp(n,vector<int>(m,0));
        dp[0][0]=1;
        for(int i=1;i<n;i++){
            if(grid[i][0]==0){
                dp[i][0]=dp[i-1][0];
            }
        }
        for(int j=1;j<m;j++){
            if(grid[0][j]==0){
                dp[0][j]=dp[0][j-1];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[i][j]==1) {
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};