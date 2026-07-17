class Solution {
public:
  long long knapsack(vector<int>& coins,int amount,int n,vector<vector<long long>>& dp){
    if(n==0){
        return 0;
    }
    if(amount==0){
        return 1;
    }
    
    if(dp[n][amount]!=-1){
        return dp[n][amount];
    }

    if(coins[n-1]<=amount){
        return dp[n][amount]=knapsack(coins,amount-coins[n-1],n,dp) + knapsack(coins,amount,n-1,dp);
    }

    else if(coins[n-1]>amount){
        return dp[n][amount]=knapsack(coins,amount,n-1,dp);
    }
    return dp[n][amount];
  }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();

        vector<vector<long long>>dp(n+1,vector<long long>(amount+1,-1));
        return knapsack(coins,amount,n,dp);
    }
};