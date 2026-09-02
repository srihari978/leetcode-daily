class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        vector<long long>pref;
        int maxi=0;
       long long sum=0;
        for(long long i:nums){
              sum+=i;
              pref.push_back(sum);
        }
        for(int i=0;i<pref.size();i++){
            if(pref[i]>0) maxi++;
        }
       return maxi; 
    }
};