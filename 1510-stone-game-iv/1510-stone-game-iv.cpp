class Solution {
public:
    bool solve( vector<int>& arr, int n,vector<int>&dp) {
        if (n == 0) return false;
        if(dp[n]!=-1) return dp[n];
            for (int k = 0; k < arr.size(); ++k) {
                if (arr[k] <= n) {
                    bool result = solve( arr, n-arr[k],dp);
                    if (result == false) {
                        return dp[n]=true;
                    }
                }
            }
        
        return dp[n]=false;
    }
     bool winnerSquareGame(int n) {
        vector<int> arr;
        for (int i = 1; i * i <= n; ++i) {
            arr.push_back(i * i);
        }

        vector<int>dp(n+1,-1);
        return solve( arr, n,dp);

    }
};