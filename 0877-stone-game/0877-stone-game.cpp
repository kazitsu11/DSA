class Solution {
public:
int dp[501][501];
int solve(int i,int j,vector<int>&piles){
    if(i==j) return piles[i];
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MIN;

    int take_left=piles[i]-solve(i+1,j,piles);
    int take_right=piles[j]-solve(i,j-1,piles);
    ans=max({ans,take_left,take_right});

    return dp[i][j]=ans;
}

    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        memset(dp,-1,sizeof(dp));
        if(solve(0,n-1,piles)>0){
            return true;
        }
        return false;
    }
};