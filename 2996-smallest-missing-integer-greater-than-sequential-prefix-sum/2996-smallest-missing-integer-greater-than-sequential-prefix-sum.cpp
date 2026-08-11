class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for (int i = 0; i < n; ++i) {
            st.insert(nums[i]);
        }
        int miss = nums[0];
        int i=1;
            while(i<n && nums[i]==nums[i-1]+1){
            miss += nums[i];
            ++i;
            }

       while(st.find(miss)!=st.end()){
        miss++;
       }
        return miss;
    }
};