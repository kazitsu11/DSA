class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mnm = *min_element(nums.begin(), nums.end());
        int mxm = *max_element(nums.begin(), nums.end());

        int n = nums.size();
        int min_idx = 0;
        int max_idx = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == mxm) {
                max_idx = i;
            }
            if (nums[i] == mnm) {
                min_idx = i;
            }
        }
        int ans = min({max(min_idx, max_idx) + 1, n - min(min_idx, max_idx),
                       min(min_idx, max_idx) + 1 + n - max(min_idx, max_idx)});
        
        return ans;
    }
};