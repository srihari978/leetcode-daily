class Solution {
     int function(int index,vector<int>& prices,int buy,int fee,vector<vector<int>>&dp){
        if(index==prices.size()) return 0;
        // if(dp[index][buy][buyallowed]!=-1) return dp[index][buy][buyallowed];
        if(dp[index][buy]!=-1) return dp[index][buy];
        if(buy){
           return dp[index][buy]=max(-prices[index]+function(index+1,prices,0,fee,dp),0+function(index+1,prices,1,fee,dp));
        }
        else{
           return dp[index][buy]=max(prices[index]-fee+function(index+1,prices,1,fee,dp),0+function(index+1,prices,0,fee,dp));
        }
        
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
       
        int n=prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
         for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    dp[index][buy]=max(-prices[index]+dp[index+1][0],dp[index+1][1]);
                }
                else{
                    dp[index][buy]=max(prices[index]-fee+dp[index+1][1],dp[index+1][0]);
                }
            }
         }
         return dp[0][1];
        
        
    }
};