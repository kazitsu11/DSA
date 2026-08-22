class Solution {
public:
void solve(vector<int>&nums,vector<int>&curr,vector<vector<int>>&res,vector<bool>&used){
 if(curr.size()==nums.size()){
    res.push_back(curr);
    return;
 }

 for(int i=0;i<nums.size();++i){
    if(used[i]) continue;
    if(i>0 && nums[i]==nums[i-1] && !used[i-1]) continue;
    used[i]=true;
    curr.push_back(nums[i]);
    solve(nums,curr,res,used);
    curr.pop_back();
    used[i]=false;
 }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>curr;
        vector<vector<int>>res;
        vector<bool>used(nums.size(),false);
        sort(nums.begin(),nums.end());
        solve(nums,curr,res,used);
        return res;
    }
};