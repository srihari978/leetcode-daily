class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];   // Descending end
                 return a[0] < b[0];       // Ascending start
             });
        int left=intervals[0][0];
        int right=intervals[0][1];
        int c=intervals.size();
        for(int i=1;i<intervals.size();i++){
            if( right>=intervals[i][1]){
              c--;
            }
            else{
                right=intervals[i][1];
            }
        }
       return c; 
    }
};