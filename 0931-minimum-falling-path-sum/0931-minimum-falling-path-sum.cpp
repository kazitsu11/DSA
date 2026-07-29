class Solution {
public:
int dp[101][101];
    int solve(int i, int j, vector<vector<int>>& matrix,vector<vector<int>>&dp) {
        if (i < 0 || j < 0 || i>=matrix.size() || j>=matrix[0].size()) return INT_MAX;
        if(i==0) return matrix[0][j];
          
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        int up=solve( i-1,j,matrix,dp);
        int up_left=solve(i-1,j-1,matrix,dp);
        int up_right=solve(i-1,j+1,matrix,dp);

        int best=min({up,up_left,up_right});
         //if(best==INT_MAX) return INT_MAX;
        return dp[i][j]=best+matrix[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
       
        int ans = INT_MAX;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MIN));
        for (int j = 0; j < n; ++j) {
            ans = min(ans, solve(n - 1, j, matrix,dp));
        }
        return ans;
    }
};