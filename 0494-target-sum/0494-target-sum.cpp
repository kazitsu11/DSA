class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }

        int target2 = (sum + target) / 2;
        if(target>sum || (target+sum)%2!=0){
        return 0;
        }
        if(target2<0){
            return 0;
        }
        vector<vector<int>> dp(n + 1, vector<int>(target2 + 1, 0));

        dp[0][0]=1;
        for (int i = 1; i < n + 1; ++i) {
            if(nums[i-1]==0){
                dp[i][0]=2*dp[i-1][0];
            }
            else{
                dp[i][0]=dp[i-1][0];
            }
        }
        for (int j = 1; j < target2 + 1; ++j) {
            dp[0][j] = 0;
        }

        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < target2 + 1; ++j) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][target2];
    }
};