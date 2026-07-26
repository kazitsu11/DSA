class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1,
                                            vector<vector<int>>& series2) {
        vector<vector<int>> res;

        int left = 0;
        int right = 0;

        int n = series1.size();
        int m = series2.size();

        while (left < n && right < m) {
            if (series1[left][0] == series2[right][0]) {
                res.push_back(
                    {series1[left][0], series1[left][1] + series2[right][1]});
                left++;
                right++;

            } else if (series1[left][0] < series2[right][0]) {
                res.push_back(
                    {series1[left][0], series1[left][1] + series2[right][1]});
                left++;

            } else if (series1[left][0] > series2[right][0]) {
                res.push_back(
                    {series2[right][0], series1[left][1] + series2[right][1]});
                right++;
            }
        }

        while (left<n) {
            res.push_back({series1[left][0], series1[left][1]});
            left++;
        }
        while (right<m) {
            res.push_back({series2[right][0], series2[right][1]});
            right++;
        }
        return res;
    }
};