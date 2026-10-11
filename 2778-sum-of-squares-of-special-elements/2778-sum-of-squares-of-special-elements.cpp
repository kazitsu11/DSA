class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n + 1,0);

        int sum = 0;
        for (int i = 1; i < n + 1; ++i) {
            arr[i] = nums[i-1];
        }
        for (int i = 1; i < n + 1; ++i) {
            if (n % i == 0) {
                sum += arr[i] * arr[i];
            }
        }
        return sum;
    }
};