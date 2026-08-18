class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        unordered_map<int, int> appear;

        int left = 0;
        for (int right = 0; right < n; ++right) {
            mp[nums[right]]++;
            if (right - left + 1 > k) {
                mp[nums[left]]--;
                left++;
            }

            if (right - left + 1 == k) {
                for (auto& a : mp) {
                    if (a.second > 0) {
                        appear[a.first]++;
                    }
                }
            }
        }

        vector<int> ans;

        for (auto& a : appear) {
            if (a.second == 1) {
                ans.push_back(a.first);
            }
        }
        if(ans.size()==0) return -1;

        int mxm = *max_element(ans.begin(), ans.end());

        return mxm;
    }
};