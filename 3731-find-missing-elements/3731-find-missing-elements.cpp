class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        sort(nums.begin(),nums.end());
        set<int>st;

        for(int i=0;i<n;++i){
           st.insert(nums[i]);
        }

        int curr=nums[0];

        while(curr<nums[n-1]){
            if(st.find(curr)==st.end()){
                ans.push_back(curr);
            }
            curr++;
        }

        return ans;
    }
};