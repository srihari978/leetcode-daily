class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int sum=0;
        // int left=0;
        // int right=piles.size()-1;
        // int sum=0;
        // while(left<right){
        //  left++;
        //  right=right-2;
        //  sum+=piles[right+1];
        // }
        // return sum;
        int j=piles.size()-2;
        for(int i=0;i<piles.size()/3;i++){
            sum+=piles[j];
            j-=2;
        }
        return sum;
    }
};