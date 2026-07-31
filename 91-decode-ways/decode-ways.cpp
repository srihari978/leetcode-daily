class Solution {
    // int f(int i, string &s,vector<int>&dp) {
    //     if (i == s.length()) return 1;
    //     if (s[i] == '0') return 0;
    //     int one=f(i+1,s,dp);
    //     int two=0;
    //     if(i+1<s.length()){
    //         int num=(s[i]-'0')*10+(s[i+1]-'0');
    //         if(num>=10 && num<=26){
    //              two=f(i+2,s,dp);
    //         }
    //     }
    //     return dp[i]=one+two;
    // }    

public:
    int numDecodings(string s) {
        int n = s.length();

        if (n == 0 || s[0] == '0')
            return 0;
        vector<int>dp(n+1,0);
         dp[0]=1;
         dp[1]= 1;
         for(int i=2;i<=n;i++){
            int one=s[i-1]-'0';
            int two=(s[i-2]-'0') *10+(s[i-1]-'0');
            if(one<=9 && one>=1){
              dp[i]+=dp[i-1];
            }
            if(two>=10 && two<=26){
            dp[i]+=dp[i-2];
            }
         }
         return dp[n];
    }
};