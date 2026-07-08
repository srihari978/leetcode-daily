class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& i) {
        sort(i.begin(),i.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });
        int right=i[0][1];
        int left=i[0][0];
        int c=0;
        for(int a=1;a<i.size();a++){
            if(right>i[a][0]){
                c++;
            }
            else{
                right=i[a][1];
            }
        }

     return c;   
    }
};