class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        if (nums.size() == 0) {
            return 0;
        }

        for (auto& a : nums) {
            st.insert(a);
        }
        int ans = 0;
       
        for (auto& a :st) {
            if (st.find(a - 1) == st.end()) {
                int curr = a;
                int count = 0;
            
            while(st.find(curr) != st.end()) {
                count++;
                curr++;
            }
             ans = max(ans, count);
            }

        }
        return ans;
    }
};