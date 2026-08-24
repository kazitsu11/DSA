class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
       int n = stones.size();
        vector<int> preSum(n);
        preSum[0] = stones[0];
        for (int i = 1; i < n; ++i) {
            preSum[i] = preSum[i - 1] + stones[i];
        }
        vector<int>dp(n,0);
        dp[n-1]=preSum[n-1];
        int ans=INT_MIN;

        for(int i=n-2;i>=1;--i){
            int take=preSum[i]-dp[i+1];
            int skip=dp[i+1];
            ans=max({ans,take,skip});
            dp[i]=ans;
        }
        return dp[1];
    }
};