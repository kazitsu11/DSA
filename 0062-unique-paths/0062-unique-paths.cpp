class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {0, 1}};
    int dfs(int i, int j, int n, int m, vector<vector<int>>& dp) {
        if (i == n - 1 && j == m - 1) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int count = 0;

        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (new_i >= 0 && new_j >= 0 & new_i < n && new_j < m) {
                count += dfs(new_i, new_j, n, m, dp);
            }
        }
        return dp[i][j] = count;
    }
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return dfs(0, 0, n, m, dp);
    }
};