class Solution {
    
    private:
    int  ispalindrome(int left,int right, string &s){
        int count=0;
       while(left>=0 && right <s.length() && s[left]==s[right]){
         count++;
        left--;
        right++;
       
       }
     return count;
    }
public:
    int countSubstrings(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
           ans+=ispalindrome(i,i,s);
           ans+=ispalindrome(i,i+1,s);
        }
        return ans;
    }
};