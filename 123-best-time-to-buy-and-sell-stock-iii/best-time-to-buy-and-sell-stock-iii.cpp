class Solution {
   
    int function(int index,vector<int>& prices,int buy,int buyallowed,vector<vector<vector<int>>>&dp){
        if(index==prices.size()|| buyallowed ==0) return 0;
        if(dp[index][buy][buyallowed]!=-1) return dp[index][buy][buyallowed];
        if(buy){
           return dp[index][buy][buyallowed]=max(-prices[index]+function(index+1,prices,0,buyallowed,dp),
            0+function(index+1,prices,1,buyallowed,dp));
        }
        else{
           return  dp[index][buy][buyallowed]=max(prices[index]+function(index+1,prices,1,buyallowed-1,dp),
            0+function(index+1,prices,0,buyallowed,dp));
        }
        
    }

public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
       vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        // return function(0,prices,1,2,dp);
         for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy) {
                        dp[index][buy][cap] = max(
                            -prices[index] + dp[index + 1][0][cap],   // Buy
                            dp[index + 1][1][cap]                      // Skip
                        );
                    }
                    else {
                        dp[index][buy][cap] = max(
                            prices[index] + dp[index + 1][1][cap - 1], // Sell
                            dp[index + 1][0][cap]                       // Hold
                        );
                    }

                }
            }
        }

        return dp[0][1][2];
        
        
    }
};