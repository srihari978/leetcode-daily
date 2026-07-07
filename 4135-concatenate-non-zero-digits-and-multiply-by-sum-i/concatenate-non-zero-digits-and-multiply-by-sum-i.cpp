class Solution {
public:
    long long sumAndMultiply(int n) {
        int temp=n;
        int x,sum=0;
        vector<int>a;
        int place=10;
        while(temp>0){
            x=temp%10;
            if(x>0){
            sum=sum+x;
            a.push_back(x);
            }
            temp=temp/10;
        }
        long long  ans=0;
        reverse(a.begin(),a.end());
        for(int i=0;i<a.size();i++){
           ans=a[i]+(ans*10);

        }
        return ans*sum;
    }
};