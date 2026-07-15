class Solution {
public:
int subset(vector<vector<bool>>& dp,int n,vector<int>& nums,int sum){
    for(int i=0;i<n+1;++i){
                dp[i][0]=true;
            }
            for(int j=1;j<sum+1;++j){
                dp[0][j]=false;
            }

            for(int i=1;i<n+1;++i){
                for(int j=1;j<sum+1;++j){
                    if(nums[i-1]<=j){
                        dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                    }
                    else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
            return dp[n][sum];
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
          int sum=0;
        for(int i=0;i<n;++i){
           sum+=nums[i];
        }
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));

        if(sum%2==0)
            return subset(dp,n,nums,sum/2);

        else{
            return false;
        }
        return dp[n][sum];
    }
};