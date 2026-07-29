class Solution {
public:
// int dp[201][201];
int solve(int i,int j,vector<vector<int>>& triangle, vector<vector<int>>&dp){
    if(j<0 || j>i) return INT_MAX;
    if(i==triangle.size()-1) return triangle[i][j];

    if(dp[i][j]!=INT_MIN) return dp[i][j];

    int down=solve(i+1,j,triangle,dp);
    int dia=solve(i+1,j+1,triangle,dp);

    int sum=min(down,dia);

    return dp[i][j]=sum+triangle[i][j];
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[0].size();
       vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MIN));
       return solve(0,0,triangle,dp);
    }
};