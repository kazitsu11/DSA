class Solution {
public:
bool solve(vector<int>&nums,vector<int>&sets,int target,int idx){
    int k=sets.size();
    if(idx==nums.size()){
    return sets[k-1]==target;
    }

    for(int i=0;i<k;++i){
        if(sets[i]+nums[idx]>target) continue;
        if(i>0 && sets[i]==sets[i-1]) continue;

        sets[i]+=nums[idx];
        if(solve(nums,sets,target,idx+1)) return true;
        sets[i]-=nums[idx];
    }
    return false;
}
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        for(auto& a:nums){
            sum+=a;
        }
        if(sum%k!=0) return false;
        int target=sum/k;

        vector<int>sets(k,0);
        sort(nums.begin(),nums.end(),greater<int>());

        return solve(nums,sets,target,0);
    }
};