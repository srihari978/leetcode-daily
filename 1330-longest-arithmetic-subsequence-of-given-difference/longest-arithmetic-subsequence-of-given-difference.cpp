class Solution {
public:
    int longestSubsequence(vector<int>& arr, int k) {

        unordered_map<int, int> dp;

        int ans = 0;

        for (int i = 0; i < arr.size(); i++) {

            int prevValue = arr[i] - k;

            dp[arr[i]] = dp[prevValue] + 1;

            ans = max(ans, dp[arr[i]]);
        }

        return ans;
    }
};