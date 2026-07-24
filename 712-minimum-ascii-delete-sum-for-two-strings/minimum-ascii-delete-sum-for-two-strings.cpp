class Solution {
    private:
    int ASCIImin(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        if(i==s1.size() && j==s2.size()) return 0;
        if(i==s1.size()&& j<s2.size()){
            int sum=0;
           for(int a=j;a<s2.size();a++){
            int ch=s2[a];
            sum+=ch;
           }
           return sum;
        }
        if(j==s2.size()&& i<s1.size()){
            int sum=0;
           for(int a=i;a<s1.size();a++){
            int ch=s1[a];
            sum+=ch;
           }
           return sum;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=ASCIImin(i+1,j+1,s1,s2,dp);
        return dp[i][j]=min(s1[i]+ASCIImin(i+1,j,s1,s2,dp),s2[j]+ASCIImin(i,j+1,s1,s2,dp));
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return ASCIImin(0,0,s1,s2,dp);
    }
};