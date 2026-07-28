class Solution {
public:
unordered_set<string>st;

bool solve(int idx,string&s,vector<int>&dp,int n){
    if(idx==n){
        return true;
    }

    if(dp[idx]!=-1){
        return dp[idx];
    }

    for(int i=1;i<=n;++i){
        string temp=s.substr(idx,i);
        if(st.find(temp)!=st.end() && solve(idx+i,s,dp,n)){
            return dp[idx]=true;
        }
    }

    return dp[idx]=false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<int>dp(n,-1);
     for(auto& a:wordDict){
        st.insert(a);
     }
     return solve(0,s,dp,n);
    }
};