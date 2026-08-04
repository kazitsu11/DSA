class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>count(n,1);
        int maxlen=1;

        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
              if(nums[i]>nums[j]){
                int candidate=1+dp[j];

                if(candidate>dp[i]){
                    dp[i]=candidate;
                    count[i]=count[j];
                }
               else if(dp[i]==candidate) count[i]+=count[j];
              }
            }
            maxlen=max(maxlen,dp[i]);
        }
     int ans=0;

     for(int i=0;i<n;++i){
        if(maxlen==dp[i]){
            ans+=count[i];
        }
     }
     return ans;
    }
};