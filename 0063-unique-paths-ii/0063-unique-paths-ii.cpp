class Solution {
public:
int dp[101][101];
int solve(vector<vector<int>>& grid,int i,int j){
 if(i<0 || j<0) return 0;
  if(grid[i][j]==1) return 0;
 if(i==0 && j==0) return 1;

 if(dp[i][j]!=-1) return dp[i][j];

 int up=solve(grid,i-1,j);
 int left=solve(grid,i,j-1);

 return dp[i][j]=up+left;
}
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(grid,n-1,m-1);
    }
};