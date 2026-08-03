class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < strs.size(); ++i) {
            int zero = 0;
            int one = 0;
            for (int j = 0; j < strs[i].size(); ++j) {
                if (strs[i][j] == '0')
                    zero++;
                else
                    one++;
            }

            for (int z = m; z >= zero; --z) {
                for (int o = n; o >= one; --o) {
                    dp[z][o] = max(1 + dp[z - zero][o - one], dp[z][o]);
                }
            }
        }
        return dp[m][n];
    }
};