class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int,int>mp;
        int n=s.size();
       
       for(auto& a:s){
        mp[a]++;
       }

       for(int i=0;i<n;++i){
        if(mp[s[i]]==1){
            return i;
        }
       }
       return -1;

    }
};