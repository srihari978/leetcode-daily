class Solution {
public:
    string removeKdigits(string num, int k) {
     stack<char>st;
        for(char i:num){
            int c=i-'0';
            while(!st.empty() && st.top()>i && k>0){
                st.pop();
                k--;
            }
            st.push(i);
        }
       while (k > 0) {
            st.pop();
            k--;
        }
      string ans="";
      while(!st.empty()){
        ans += st.top();
        st.pop();
      }
    reverse(ans.begin(), ans.end());
    int i=0;
    while(i<ans.size()&& ans[i]=='0'){
        i++;
    }
    ans = ans.substr(i);
    if(ans.empty()){
        return "0";
    }
    return ans;
    }
};