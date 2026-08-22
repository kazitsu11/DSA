class Solution {
public:
void solve(vector<int>&nums,vector<int>&curr,vector<vector<int>>&res,vector<bool>used){
    int n=nums.size();
    if(curr.size()==n){
    res.push_back(curr);
    return;
    }

    for(int i=0;i<n;++i){
        if(used[i]) continue;
        used[i]=true;
        curr.push_back(nums[i]);
        solve(nums,curr,res,used);
        curr.pop_back();
        used[i]=false;
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>curr;
        vector<vector<int>>res;
        int n=nums.size();
        vector<bool>used(n,false);
        solve(nums,curr,res,used);
        return res;
    }
};
