class Solution {
    private:
    int solve (int i,int j,string s1,string s2,vector<vector<int>>&dp){
        if(i>=s1.size()|| j>=s2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=1+solve(i+1,j+1,s1,s2,dp);
        int left=solve(i,j+1,s1,s2,dp);
        int right=solve(i+1,j,s1,s2,dp);
        return dp[i][j]= max(left,right);

    }
public:
    int longestCommonSubsequence(string text1, string text2) {
    //     // vector<vector<int>> dp(text1.size()+ 1, vector<int>(text2.size()+1, -1));
    //     // return solve(0,0,text1,text2,dp);
    //     int n=text1.size();
    //     int m=text2.size();
    //     vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    //     for(int i=0;i<n;i++){
    //         dp[i][0]=0;
    //     }
    //      for(int i=0;i<m;i++){
    //         dp[0][i]=0;
    //     }
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=m;j++){
    //             if(text1[i-1]==text2[j-1])  
    //             {
    //                 dp[i][j]=1+dp[i-1][j-1];
    //             }
    //             else{
    //                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    //             }
    //         }
    //     }
        
    //    return dp[n][m]; 
    int m=text2.size();
    int n=text1.size();
     vector<int>prev(m+1,0);
     vector<int>curr(m+1,0);
     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(text1[i-1]==text2[j-1]){
                curr[j]=1+prev[j-1];
            }
            else{
               curr[j]= max(prev[j], curr[j-1]);
            }
        }
        prev=curr;
     }

return prev[m];








    }
};