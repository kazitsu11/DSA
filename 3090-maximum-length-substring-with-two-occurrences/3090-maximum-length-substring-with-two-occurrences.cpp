class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        unordered_map<int,int>mp;
        int maxlen=1;
       
       int i=0;
       int left=0;
        while(i<n){
            mp[s[i]]++;
            while(mp[s[i]]>2){
                mp[s[left]]--;
               left++;
            }
         maxlen=max(maxlen,i-left+1);
            i++;
        }
        return maxlen;
    }
};