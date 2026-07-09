class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });
        int c=1;
        int right=pairs[0][1];
        for(int i=1;i<pairs.size();i++){
            if(right<pairs[i][0]){
                c++;
                right=pairs[i][1];
            }
        }
       return c; 
    }
};