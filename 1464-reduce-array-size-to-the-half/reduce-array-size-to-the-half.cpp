class Solution {
public:
    int minSetSize(vector<int>& arr) {
     map<int,int>mp;
     for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
     }  
     vector<int>freq;
      for (auto it : mp) {
            freq.push_back(it.second);
        }
     sort(freq.begin(),freq.end(),greater<int>());
     int c=0;
     int removed=0;
     for(int i=0;i<freq.size();i++){
        removed+=freq[i];
        c++;
        if(removed>=arr.size()/2) break;
     }
     return c;
    }
};