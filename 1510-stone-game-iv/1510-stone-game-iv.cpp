class Solution {
public:
    bool solve(int alice, int bob, vector<int>& arr, int n,vector<int>&dp) {
        if (n == 0) return false;
        if(dp[n]!=-1) return dp[n];
        if (alice == 1) {
            for (int k = 0; k < arr.size(); ++k) {
                if (arr[k] <= n) {
                    bool result = solve(0, 1, arr, n-arr[k],dp);
                    if (result == false) {
                        return dp[n]=true;
                    }
                }
            }
        } 
        else if (bob == 1) {
            for (int k = 0; k < arr.size(); ++k) {
                if (arr[k] <= n) {
                    bool result = solve(1, 0, arr, n-arr[k],dp);
                    if (result == false) {
                        return dp[n]=true;
                    }
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
        return solve(1, 0, arr, n,dp);

    }
};