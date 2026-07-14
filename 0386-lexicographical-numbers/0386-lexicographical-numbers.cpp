class Solution {
public:
vector<int>ans;
void dfs (int nums,vector<int>&ans,int n){
    if(nums>n){
        return;
    }
    ans.push_back(nums);

    for(int digit=0;digit<=9;++digit){
       int child=1LL*nums*10+digit;
        if(child>n){
            return;
        }
        dfs(child,ans,n);
    }    
}
    vector<int> lexicalOrder(int n) {
        long long nums;
        for(int i=1;i<=9;++i){
             nums=i;
            dfs(nums,ans,n);
        }
        return ans;
    }
};