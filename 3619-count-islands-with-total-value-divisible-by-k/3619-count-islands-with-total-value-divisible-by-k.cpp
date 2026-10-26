class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>&vis,long long &sum) {
        int n = grid.size();
        int m = grid[0].size();

         sum += grid[i][j];

        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (new_i >= 0 && new_j >= 0 && new_i < n && new_j < m && grid[new_i][new_j] > 0 && vis[new_i][new_j] == 0) {
                vis[new_i][new_j] = 1;
                dfs(new_i, new_j, grid,vis,sum);
            }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                 long long sum=0;
                if (grid[i][j] > 0 && vis[i][j] == 0) {
                    vis[i][j] = 1;
                     dfs(i, j, grid,vis,sum);
                    if (sum% k == 0) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};