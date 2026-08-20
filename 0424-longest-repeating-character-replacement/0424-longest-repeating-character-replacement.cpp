class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<char,int>mp;
        int maxlen=1;
        int canChange=k;
        int left=0;
        int right=1;
        
        for(int right=0;right<n;++right){
            mp[s[right]]++;
            int maxfreq=0;
            for(auto & a:mp){
                maxfreq=max(maxfreq,a.second);
            }
           while((right-left+1)-maxfreq>k){
            mp[s[left]]--;
             left++;
           }
           maxlen=max(maxlen,right-left+1);
        }
     return maxlen;
    }
};