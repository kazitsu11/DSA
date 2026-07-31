class Solution {
public:
int dp[101][101];
bool solve(int i,int j,string &s1,string&s2,string&s3){
    
    if(i==s1.size() && j==s2.size()) return true;

    if(dp[i][j]!=-1) return dp[i][j];

    bool ans=false;

    if(i<s1.size() && s1[i]==s3[i+j]){
        ans= ans || solve(i+1,j,s1,s2,s3);
    }
     if(j<s2.size() && s2[j]==s3[i+j]){
        ans=ans || solve(i,j+1,s1,s2,s3);
    }

    return dp[i][j]=ans;
}
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        memset(dp,-1,sizeof(dp));

        if(n+m <s3.size()){
            return false;
        }
        return solve(0,0,s1,s2,s3);
    }
};
