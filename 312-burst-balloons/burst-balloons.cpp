class Solution {
private:
    int solve(int i, int j, vector<int>& nums,vector<vector<int>>&dp) {

        // No balloons left
        if (i > j)
            return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi = 0;

        // Choose k as the LAST balloon to burst
        for (int k = i; k <= j; k++) {

            int coins =
                nums[i - 1] * nums[k] * nums[j + 1]
                + solve(i, k - 1, nums,dp)
                + solve(k + 1, j, nums,dp);

            maxi = max(maxi, coins);
        }

        return dp[i][j]=maxi;
    }

public:
    int maxCoins(vector<int>& nums) {

        // Add boundary balloons
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
         vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(1, nums.size() - 2, nums,dp);
    }
};