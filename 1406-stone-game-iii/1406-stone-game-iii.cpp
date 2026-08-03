class Solution {
public:
    string stoneGameIII(vector<int>& val) {
        int n = val.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            int ans = INT_MIN;
            int sum = 0;
            for (int j = 0; j < 3; ++j) {
                if (i + j < n) {
                    sum += val[i + j];
            ans=max(ans,sum-dp[i+j+1]);
                }
            }
            dp[i] = ans;
        }

        int diff=dp[0];
        if(diff>0) return "Alice";
        if(diff<0) return "Bob";
        else return "Tie";
    }
};