class Solution {
public:
//int dp[30001][10001];
int solve(int i,int buy,vector<int>&prices,vector<vector<int>>&dp){
    if(i>=prices.size())  return 0;

    if(dp[i][buy]!=-1)  return dp[i][buy];

    int profit=INT_MIN;

    if(buy==1){
        int take=solve(i+1,0,prices,dp)-prices[i];
        int not_take=solve(i+1,1,prices,dp);
        profit=max({profit,take,not_take});
    }

    if(buy==0){
        int sell=solve(i+1,1,prices,dp)+prices[i];
        int not_sell=solve(i+1,0,prices,dp);
        profit=max({profit,sell,not_sell});
    }
    return dp[i][buy]=profit;
}
    int maxProfit(vector<int>& prices) {
        //memset(dp,-1,sizeof(dp));
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};