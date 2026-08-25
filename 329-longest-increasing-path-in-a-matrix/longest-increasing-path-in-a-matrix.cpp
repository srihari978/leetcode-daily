class Solution {
    private:
    int dfs(int i,int j,vector<vector<int>>& matrix,int row,int cols,vector<vector<int>>& dp){
        if(dp[i][j]!=-1) return dp[i][j];
        int dirs[]={0,1,0,-1,0};
        int best = 1;
        for(int k=0;k<4;k++){
            int ni=i+dirs[k],nj=j+dirs[k+1];
       if(ni>=0 && ni<row && nj>=0 && nj<cols && matrix[ni][nj]>matrix[i][j]){
         best = max(best, 1 + dfs(ni, nj, matrix, row, cols,dp));
       } 
        }
        return dp[i][j]=best;
        }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int ans=1;
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<vector<int>>dp(rows,vector<int>(cols,-1));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                ans=max(ans,dfs(i,j,matrix,rows,cols,dp));
            }
        }
        return ans;
    }
};