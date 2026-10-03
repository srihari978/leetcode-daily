class Solution {
public:
    int minimumCardPickup(vector<int>& nums) {
        int ans=INT_MAX;
        int left=0;
        unordered_set<int>seen;
        for(int right=0;right<nums.size();right++){
            while(seen.find(nums[right])!=seen.end()){
                seen.erase(nums[left]);
                ans=min(ans,right-left+1);
                left++;
            }
            seen.insert(nums[right]);
        }
        return ans==INT_MAX?-1:ans;}
};