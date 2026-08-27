class Solution {
    int solve(int i, vector<int>& nums, int n, int target,
              vector<vector<int>> dp) {
        if (i >= n || target < 0)
            return false;
        if (target == 0)
            return true;
        if (dp[i][target] != -1)
            return dp[i][target];
        int nottake = solve(i + 1, nums, n, target, dp);
        int take = 0;
        if (target >= nums[i])
            take = nums[i] + solve(i + 1, nums, n, target - nums[i], dp);
        return dp[i][target] = take || nottake;
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i : nums)
            sum += i;
        if (sum % 2 != 0)
            return false;
        sum=sum/2;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1, 0));
        // return solve(0, nums, nums.size(), sum,dp);
        for(int i=0;i<nums.size();i++){
            dp[i][0]=true;
        }
        for(int i=1;i<=nums.size();i++){
            for(int target=1;target<=sum;target++){
                bool nottake=dp[i-1][target];
                bool take=false;
                if(target>=nums[i-1]) take=dp[i-1][target-nums[i-1]];
                dp[i][target] =take||nottake;
            }
        }
        return dp[nums.size()][sum];
    }
};