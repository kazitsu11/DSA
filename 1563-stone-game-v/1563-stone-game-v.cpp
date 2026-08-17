class Solution {
public:

int dp[501][501];
vector<int>preSum;
int getsum(int left,int right){
    int sum=preSum[right+1]-preSum[left];
    return sum;
}
    int solve(int left, int right, vector<int>& val) {
        if (left == right) return 0;
        if(dp[left][right]!=-1) return dp[left][right];
        int ans = 0;

        for (int i = left; i < right; ++i) {
           
               int left_r=getsum(left,i);
               int right_r=getsum(i+1,right);
            

            if (left_r < right_r) {
                ans = max(ans, left_r + solve(left, i, val));
            }
            else if (left_r > right_r) {
                ans = max(ans, right_r + solve(i + 1, right, val));
            }
            else{
                ans=max(ans,left_r+max(solve(left,i,val),solve(i+1,right,val)));
            }
        }

        return dp[left][right]=ans;
    }
    int stoneGameV(vector<int>& val) {
        int n = val.size();

        preSum.resize(n+1,0);
        int sum=0;
        for(int i=0;i<n;++i){
            sum+=val[i];
            preSum[i+1]=sum;
        }
        memset(dp,-1,sizeof(dp));
        return solve(0, n - 1, val);
    }
};