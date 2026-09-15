class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.length();
        unordered_map<int,int>mp;
        char ans;

        for(auto& a:s){
            mp[a]++;
        }
        for(int i=0;i<n;++i){
            if(mp[s[i]]==1) return i;
        }
      return -1;
    }
};