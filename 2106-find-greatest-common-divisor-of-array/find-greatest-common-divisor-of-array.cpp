class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int small=nums[0];
        int largest= nums[n-1];
        int maxi=1;
        for(int i=1;i<=small;i++){
            if(small%i==0 && largest%i==0){
                maxi=i;
            }
        }
        return maxi;
    }
};