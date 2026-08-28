class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        long long x = LLONG_MIN;
        long long y = LLONG_MIN;
        long long z = LLONG_MIN;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == x || nums[i] == y || nums[i] == z)
                continue;
            if (nums[i] > x) {
                z=y;
                y=x;
                x = nums[i];
            } else if (nums[i] > y) {
                z=y;
                y = nums[i];
            } else if(nums[i]>z) {
                z = nums[i];
            }
        }
        if (z == LLONG_MIN)
            return x;

        return z;
    }
};