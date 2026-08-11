class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=0;
        int n=s.size();
        int maxlen=0;
        int currlen;
        
        unordered_set<int>st;
        for(int i=0;i<n;++i){
            while(st.find(s[i])!=st.end()){
             st.erase(s[left]);
             left++;
            }
                st.insert(s[i]);
               // s[right++];
                currlen=st.size();
                maxlen=max(maxlen,currlen);
            }
        return maxlen;
    }
};