class Solution {
public:

vector<vector<int>>directions={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
double solve(int i,int j,int k,int n, vector<vector<vector<double>>>&dp){
    if(i>=n || j>=n || i<0 || j<0)  return 0.0;
   
    if(k==0) return 1.0;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    
    double ans=0.0;
    
   for(auto & dir:directions){
    int new_i=i+dir[0];
    int new_j=j+dir[1];
     
     ans+=solve(new_i,new_j,k-1,n,dp);
    
   }
    return dp[i][j][k]=ans/8.0;
}
    double knightProbability(int n, int k, int row, int column) {
        //memset(dp,-1,sizeof(dp));
        vector<vector<vector<double>>>dp(n+1,vector<vector<double>>(n+1,vector<double>(k+1,-1)));
        return solve(row,column,k,n,dp);
    }
};