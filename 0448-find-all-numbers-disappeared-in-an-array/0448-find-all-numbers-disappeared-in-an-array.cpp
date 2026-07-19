class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        unordered_map<int,int> mp;
        for(auto& a:nums){
            mp[a]++;
        }
        int curr=1;
        while(n--){
            if(mp[curr]==0){
              ans.push_back(curr);
            }
            curr++;
        }
        return ans;
    }
};