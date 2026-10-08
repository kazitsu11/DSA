class Solution {
public:

 double solve(int A,int B,vector<vector<int>>&op,vector<vector<double>>&dp){
    if(A<=0 && B>0) return 1.0;
    if(A<=0 && B<=0) return 0.5;
    if(A<=0 || B<=0) return 0.0;
    if(dp[A][B]!=-1) return dp[A][B];
    double ans=0;

    for(auto& p:op){
        int a=p[0];
        int b=p[1];

       ans+= solve(A-a,B-b,op,dp);
    }
   return dp[A][B]=ans/4.0;
 }
    double soupServings(int n) {
        if(n>5000) return 1;
         vector<vector<int>>op={{100,0},{75,25},{50,50},{25,75}};
         vector<vector<double>>dp(n+1,vector<double>(n+1,-1));
        return solve(n,n,op,dp);
    }
};