class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int sum=0;
        for(int i=0;i<n;++i){
          sum+=stones[i];
        }
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));

        for(int i=0;i<n+1;++i){
            dp[i][0]=true;
        }
        for(int j=1;j<sum+1;++j){
            dp[0][j]=false;
        }

        for(int i=1;i<n+1;++i){
            for(int j=1;j<sum+1;++j){
                if(stones[i-1]<=j){
                    dp[i][j]=dp[i-1][j-stones[i-1]]  ||  dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }

        vector<int> res;

        for(int j=0;j<sum+1;++j){
            if(dp[n][j]==true){
                res.push_back(j);
            }
        }
 
      int mnm=INT_MAX;
        for(int i=0;i<res.size();++i){
          mnm=min(mnm,abs(sum-2*res[i]));
        }
        return mnm;
    }
};