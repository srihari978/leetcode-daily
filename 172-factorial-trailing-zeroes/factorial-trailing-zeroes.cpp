class Solution {
public:
    int trailingZeroes(int n) {
        int count;
        while(n>0){
            n=n/5;
            count=count+n;
        }
      return count;  
    }
};