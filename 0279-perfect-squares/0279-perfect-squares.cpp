class Solution {
public:
    long long ks(vector<int>& arr, int target, int n, vector<vector<long long>>& dp) {

        if (target == 0) {
            return 0;
        }
        if (target == 1)
            return 1;
        if (n == 0) {
            return 1e9;
        }
        if (dp[n][target] != 1e9) {
            return dp[n][target];
        }
        if (arr[n - 1] <= target) {
            return dp[n][target] = min(1 + ks(arr, target - arr[n - 1], n, dp),
                                       ks(arr, target, n - 1, dp));
        } else if (arr[n - 1] > target) {
            return dp[n][target] = ks(arr, target, n - 1, dp);
        }
        return dp[n][target];
    }
    int numSquares(int target) {
        vector<int> arr;

        for (int i = 1; i < target; ++i) {
            if(i*i<=target)
            arr.push_back(i * i);
        }
        int n = arr.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, 1e9));

        return ks(arr, target, n, dp);
    }
};