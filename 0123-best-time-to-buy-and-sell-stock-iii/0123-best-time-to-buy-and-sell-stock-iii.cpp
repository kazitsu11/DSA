class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int t = 0; t < 2; t++) {
                if (buy == 1) {
                    int take = dp[i+1][0][t] - prices[i];
                    int not_take = dp[i+1][1][t];
                    dp[i][buy][t] = max(take, not_take);
                } else {
                    int sell = dp[i+1][1][t+1] + prices[i];
                    int not_sell = dp[i+1][0][t];
                    dp[i][buy][t] = max(sell, not_sell);
                }
            }
        }
    }

    return dp[0][1][0];
    }
};