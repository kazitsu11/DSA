class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(),pairs.end(),[](auto&a,auto&b){
            return a[1]<b[1];
        });
        vector<int> dp(n, 1);

        int ans = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (pairs[j][1] < pairs[i][0]) {
                    int candidate = 1 + dp[j];

                    if (candidate > dp[i]) {
                        dp[i] = candidate;
                    }
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};