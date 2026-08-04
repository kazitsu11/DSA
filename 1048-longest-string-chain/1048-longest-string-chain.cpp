class Solution {
public:
    bool isPred(string& s1, string& s2) {
         int left = s1.size() - 1;
            int right = s2.size() - 1;
            int diff=0;
        if (s2.size() != s1.size() + 1) {
            return false;
        }
            while (left >= 0 && right >= 0) {
                if (s1[left] == s2[right]) {
                    left--;
                    right--;
                }
                else{
                    diff++;
                    right--;
                }
            }
        return diff<=1;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);

        sort(words.begin(), words.end(), [](auto& a, auto& b) { return a.size() < b.size(); });

        int maxlis = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if(isPred(words[j],words[i])){
                    int candidate = 1 + dp[j];
                    if (candidate > dp[i]) {
                        dp[i] = candidate;
                    }
                }
            }
            maxlis = max(maxlis, dp[i]);
        }
        return maxlis;
    }
};