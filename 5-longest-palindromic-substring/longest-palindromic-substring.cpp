class Solution {
     int palindrome(int left,int right,string &s){
        while(left>=0 && right<s.length() && s[left]==s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
public:
    string longestPalindrome(string s) {
         int ans=0;
        int maxlen=0;
        int start=0;
        for (int i=0;i<s.length();i++){
          int len1= palindrome(i,i,s) ;
          int len2= palindrome(i,i+1,s);
          ans=max(len1,len2);
          if(ans>maxlen){
            maxlen=ans;
             start = i - (ans - 1) / 2;
          }
        }
        return s.substr(start,maxlen);
        
    }
};