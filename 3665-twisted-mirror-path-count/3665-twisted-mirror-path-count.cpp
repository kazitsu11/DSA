class Solution {
public:
int dp[501][501][2];
int MOD=1e9+7;
int solve(int i,int j,vector<vector<int>>&grid,int dir){
    int n=grid.size();
    int m=grid[0].size();
    if(i>n-1 || j>m-1) return 0;
    if(i==n-1 && j==m-1) return 1;
    if(dp[i][j][dir]!=-1) return dp[i][j][dir];

    if(grid[i][j]==1){
     if(dir==0){
        return solve(i+1,j,grid,1);
     }
     else{
        return solve(i,j+1,grid,0);
     }
    }

    int right=solve(i,j+1,grid,0)%MOD;
    int down=solve(i+1,j,grid,1)%MOD;

    return dp[i][j][dir]=(right+down)%MOD;
}
    int uniquePaths(vector<vector<int>>& grid) {
     memset(dp,-1,sizeof(dp));
      return solve(0,0,grid,0);  
    }
};