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
            if(freq>n/2){
                return p.first;
            }
        }
return 0;
    }
};