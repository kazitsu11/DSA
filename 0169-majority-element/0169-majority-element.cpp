class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<vector<int>> ans;
        for (auto& a : nums) {
            mp[a]++;
        }

        for (auto& p : mp) {
            int freq = p.second;

            ans.push_back({freq, p.first});
        }

        sort(ans.begin(), ans.end(), greater<vector<int>>());
        return ans[0][1];
    }
};