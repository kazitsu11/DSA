class Solution {
public:
int dp[101][101];
int solve(int i,int M,vector<int>& piles){
    int n=piles.size();
    if(i==n) return 0;
    if(dp[i][M]!=-1) return dp[i][M];

    int ans=INT_MIN;
     int sum=0;
    
    for(int x=1;x<=2*M && i+x<=n;++x){
        sum+=piles[i+x-1];
      ans=max(ans,sum-solve(i+x,max(M,x),piles));
    }
    return dp[i][M]= ans;
}
    int stoneGameII(vector<int>& piles) {
     
        int n=piles.size();
           //vector<vector<int>dp(n+1,vector<int>())
           memset(dp,-1,sizeof(dp));
        int total=0;
        for(auto& a:piles){
            total+=a;
        }
        int diff= solve(0,1,piles);
        return (total+diff)/2;
    }
};