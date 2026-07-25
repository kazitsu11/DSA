class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        if(n==1){
            return 1;
        }

      int maxlis=INT_MIN;
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                    
                }
                maxlis=max(maxlis,dp[i]);
            }
        }
        return maxlis;
    }
};