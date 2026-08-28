class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            if(nums[i-1]>=nums[i]){
                int x=nums[i-1]-nums[i]+1;
                sum+=x;
                nums[i]=x+nums[i];
            }
        }
        return sum;
    }
};