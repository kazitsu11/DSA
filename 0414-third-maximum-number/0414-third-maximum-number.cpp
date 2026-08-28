class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        set<int,greater<int>> st;
        for (int i = 0; i < n; ++i) {
            st.insert(nums[i]);
        }

        int curr = 0;
        for (auto& a : st) {
            if (curr == 2)
                return a;
            curr++;
        }
        return *max_element(nums.begin(), nums.end());
    }
};