class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
              sort(events.begin(),events.end(),[](auto &a,auto &b){
               return a[0]<b[0];
               }
              );
           int day = 1;
           int i = 0;
           int count=0;
            priority_queue<int, vector<int>, greater<int>> pq;
            while(i<events.size()|| !pq.empty()){
                  if (pq.empty()) {
                day = max(day, events[i][0]);
            }
             while(i<events.size() && events[i][0]<=day){
                  pq.push(events[i][1]);
                   i++;
             }
             while(!pq.empty() && pq.top()<day){
                pq.pop();
             }
             if(!pq.empty()){
             pq.pop();
             count++;
             }
            day++;
            }
            return count;

    }
};