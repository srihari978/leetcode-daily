class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 2; i--) {
            long long c = nums[i];
            long long b = nums[i - 1];
            long long a = nums[i - 2];
            if (a + b > c) {
                return a + b + c;
            }
        }
        return 0;
    }
};