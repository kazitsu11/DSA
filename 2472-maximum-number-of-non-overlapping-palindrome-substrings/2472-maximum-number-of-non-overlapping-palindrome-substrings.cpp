class Solution {
public:
int dp[2001][2001];
bool isPal(string&s,int i ,int j){
    while(i<=j){
        if(s[i]==s[j]){
            i++;
            j--;
        }
        else return false;
    }
    return true;
}
int solve(string& s,int k,int i,int j){
    if(j>=s.size()){
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];

    if(isPal(s,i,j)){
        int take=1+solve(s,k,j+1,j+k);
        int grow=solve(s,k,i,j+1);
        int slide=solve(s,k,i+1,j+1);
        return dp[i][j]= max({take,grow,slide});
    }
        int grow=solve(s,k,i,j+1);
        int slide=solve(s,k,i+1,j+1);
        return dp[i][j]= max(grow,slide);
}
    int maxPalindromes(string s, int k) {
        memset(dp,-1,sizeof(dp));
        int n=s.size();
        if(k==1){
            return n;
        }
        return solve(s,k,0,k-1);
    }
};