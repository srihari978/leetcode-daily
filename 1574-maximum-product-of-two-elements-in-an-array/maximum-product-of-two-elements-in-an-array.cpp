class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=nums.size();
        int maxi1=(nums[0]-1) * (nums[1]-1);
        int maxi2=(nums[i-1]-1) * (nums[i-2]-1);
        return max(maxi1,maxi2);
        
    }
};