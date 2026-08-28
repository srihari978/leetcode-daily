class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(),clips.end());
        int i=0;
        int farpoint=0;
        int currentend=0;
        int ans=0;
        while(currentend<time){
            while(i<clips.size()&&clips[i][0]<=currentend){
                farpoint=max(farpoint,clips[i][1]);
                i++;
            }
            if (farpoint == currentend)
                return -1;
            ans++;
           currentend= farpoint;
        }
        return ans;
    }
};