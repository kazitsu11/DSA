class Solution {
public:
void solve(vector<int>&digits,vector<int>&curr,vector<vector<int>>&res,vector<bool>&used){
    if(curr.size()==3){
        res.push_back(curr);
        return;
    }
    for(int i=0;i<digits.size();++i){
        if(i>0 && digits[i]==digits[i-1] && !used[i-1]) continue;
        if(used[i]==true) continue;
        used[i]=true;
        curr.push_back(digits[i]);
        solve(digits,curr,res,used);
        curr.pop_back();
        used[i]=false;
    }
}
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        vector<int>curr;
        vector<vector<int>>res;
        vector<bool>used(n,false);
        int count=0;
        sort(digits.begin(),digits.end());

        solve(digits,curr,res,used);

        for(auto&a: res){
            if(a[2]%2==0 && a[0]!=0) count++;
        }
        return count;
    }
};