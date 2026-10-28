class Solution {
public:
int solve(vector<vector<int>>&grid,int i,int j,int currxor,vector<vector<vector<int>>>&dp){
    if(i<0 || j<0) return INT_MAX;

    currxor^=grid[i][j];
    if(i==0 && j==0) return currxor;
    if(dp[i][j][currxor]!=-1) return dp[i][j][currxor];

    int left=solve(grid,i,j-1,currxor,dp);
    int up=solve(grid,i-1,j,currxor,dp);

    int ans=min(left,up);

    return dp[i][j][currxor]=ans;
}
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(1024,-1)));
         return solve(grid,n-1,m-1,0,dp);
    }
};