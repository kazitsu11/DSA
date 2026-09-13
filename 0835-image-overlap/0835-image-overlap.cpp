class Solution {
public:
    int solve(vector<vector<int>>& img1, vector<vector<int>>& img2, int row_off,int col_off) {
        int n = img1.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int new_i=i+row_off;
                int new_j=j+col_off;
                if (new_i>=0 && new_j>=0 && new_i<n && new_j<n && img1[i][j] ==1 && img2[new_i][new_j]==1) {
                    count++;
                }
            }
        }
        return count;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int overlap = 0;
        for (int row_off = -n + 1; row_off <= n - 1; ++row_off) {
            for (int col_off = -n + 1; col_off <= n - 1; ++col_off) {
                int count = solve(img1, img2, row_off, col_off);
                overlap = max(overlap, count);
            }
        }
        return overlap;
    }
};