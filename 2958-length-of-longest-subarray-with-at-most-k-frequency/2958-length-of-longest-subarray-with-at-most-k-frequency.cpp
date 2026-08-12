class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int len = 0;
        int maxlen = 1;
        int left = 0;
        int right=0;

        for (int i = 0; i < n; ++i) {
             mp[nums[i]]++; 
            while (mp[nums[i]] > k) {
                mp[nums[left]]--;
                left++;
            }
            len=right-left+1;
            maxlen=max(maxlen,len);
            right++;
        }
        return maxlen;
    }
};