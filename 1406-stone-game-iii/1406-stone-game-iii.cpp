class Solution {
public:

    int solve(int i, vector<int>& val, vector<int>& dp) {

        int n = val.size();

        if(i == n)
            return 0;

        if(dp[i] != INT_MIN)
            return dp[i];


        int ans = INT_MIN;
        int sum = 0;


        for(int k = 0; k < 3 && i+k < n; k++) {

            sum += val[i+k];

            ans = max(ans,
                sum - solve(i+k+1, val, dp)
            );
        }


        return dp[i] = ans;
    }


    string stoneGameIII(vector<int>& val) {

        int n = val.size();

        vector<int> dp(n+1, INT_MIN);

        dp[n] = 0;   // memoize base case

        int diff = solve(0,val,dp);


        if(diff > 0)
            return "Alice";
        else if(diff < 0)
            return "Bob";

        return "Tie";
    }
};