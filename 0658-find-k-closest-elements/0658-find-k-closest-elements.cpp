class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<vector<int>> diff;
        vector<int> ans(k);

        for (auto& a : arr) {
            diff.push_back({a, abs(x - a)});
        }

        sort(diff.begin(), diff.end(), [](auto& a, auto& b) {
            if (a[1] == b[1])
                return a[0] < b[0];
            return a[1] < b[1];
        });

        int curr = 0;
        for (int i = 0; i < k; ++i) {
            ans[i] = diff[curr][0];
            curr++;
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};