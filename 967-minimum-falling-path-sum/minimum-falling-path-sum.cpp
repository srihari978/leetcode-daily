class Solution { 
public: 
    int minFallingPathSum(vector<vector<int>>& matrix) { 

        int n = matrix.size(); 
        int m = matrix[0].size(); 

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX)); 

        // First row
        for(int j = 0; j < m; j++) { 
            dp[0][j] = matrix[0][j]; 
        } 

        // Remaining rows
        for(int i = 1; i < n; i++) { 

            for(int j = 0; j < m; j++) { 

                int up = dp[i-1][j];

                int left = INT_MAX;
                if(j > 0) {
                    left = dp[i-1][j-1];
                }

                int right = INT_MAX;
                if(j + 1 < m) {
                    right = dp[i-1][j+1];
                }

                dp[i][j] = matrix[i][j] + 
                           min({left, up, right});
            } 
        } 

        int ans = INT_MAX;

        // Minimum value in last row
        for(int j = 0; j < m; j++) { 
            ans = min(ans, dp[n-1][j]); 
        } 

        return ans; 
    } 
};