class Solution {
public:
void solve(int idx,int n,int k,vector<int>&curr,vector<vector<int>>&res){
    if(curr.size()==k){
        res.push_back(curr);
        return;
    }

    for(int i=idx;i<=n;++i){
        curr.push_back(i);
        solve(i+1,n,k,curr,res);
        curr.pop_back();
    }
}
    vector<vector<int>> combine(int n, int k) {
        vector<int>curr;
        vector<vector<int>>res;
        solve(1,n,k,curr,res);
        return res;
    }
};