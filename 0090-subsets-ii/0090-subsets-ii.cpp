class Solution {
public:
void solve(int idx,vector<int>&nums,vector<int>&curr,vector<vector<int>>&res){
    res.push_back(curr);
    
    for(int i=idx;i<nums.size();++i){
        if(i>idx && nums[i]==nums[i-1]) continue;
        curr.push_back(nums[i]);
        solve(i+1,nums,curr,res);
        curr.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>curr;
        vector<vector<int>>res;
        solve(0,nums,curr,res);
        return res;
    }
};
