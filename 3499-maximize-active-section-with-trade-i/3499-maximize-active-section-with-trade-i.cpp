class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        int onecount = count(s.begin(), s.end(), '1');

        int n = s.size();
        int left = 0;
        vector<int> zero;
        int i = 0;
        while (i < n) {
            if (s[i]=='0'){
                int start=i;
                while(i<n && s[i]=='0'){
                    i++;
                }
                zero.push_back(i-start);
            }
            else{
                i++;
            }
        }

        int k = zero.size();
        int maxsum = 0;
        for (int i = 1; i < k; ++i) {
            maxsum = max(maxsum, zero[i] + zero[i - 1]);
        }
        return maxsum + onecount;
    }
};