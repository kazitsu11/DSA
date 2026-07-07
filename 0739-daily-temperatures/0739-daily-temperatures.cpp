class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack < pair<int, int>> st;
        vector<int> ans;
        map<int, int> mp;

        int n = temp.size();
         ans.resize(n,0);

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && temp[i] >= st.top().first) {
                st.pop();
            }

            if (st.empty())
                ans[i] = 0;

            else
                ans[i] = st.top().second-i;
            st.push({temp[i], i});
        }
        return ans;
    }
};