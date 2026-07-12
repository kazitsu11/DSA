class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int sum = 0;
        int n = nums.size();
        vector<int> prefsum1;
        vector<int> prefsum2;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            prefsum1.push_back(sum);
        }
        sum = 0;

        for (int i = n - 1; i >= 0; --i) {
            sum += nums[i];
            prefsum2.push_back(sum);
        }
        reverse(prefsum2.begin(),prefsum2.end());

        for (int i = 0; i < n; i++) {
            if (prefsum1[i] == prefsum2[i]) {
                return i;
            }
        }
        return -1;
    }
};
