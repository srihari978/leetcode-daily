class Solution {
      int function(int index,vector<int>& prices,int buy){
        if(index>=prices.size()) return 0;
        // if(dp[index][buy]!=-1) return dp[index][buy];
        if(buy){
           return max(-prices[index]+function(index+1,prices,0), 0+function(index+1,prices,1));
        }
        else{
           return max(prices[index]+function(index+2,prices,1), 0+function(index+1,prices,0));
        }
        
    }
public:

    int maxProfit(vector<int>& prices) {
        // return function(0,prices,1);
        int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int b=0;b<=1;b++){
                if(b){
                    dp[i][b]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else{
                    dp[i][b]=max(prices[i]+dp[i+2][1],dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};