class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxreach=0;
         
         if(n==1) return true;
        for(int i=0;i<n;++i){
            if(i>maxreach) return false;
            maxreach=max(nums[i]+i,maxreach);
        }
        return true;
    }
};