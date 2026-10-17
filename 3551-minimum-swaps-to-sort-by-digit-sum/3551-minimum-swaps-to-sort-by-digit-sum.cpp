class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<vector<int>>ans;
        int i=0;
        for(auto& a:nums){
            int temp=a;
            int sum=0;
            while(temp>0){
            sum+=temp%10;
            temp/=10;
            }
            ans.push_back({sum,a,i});
            ++i;
        }
         
        sort(ans.begin(),ans.end());
        int n=ans.size();
        vector<bool>vis(n,false);
        int sw=0;
        for(int i=0;i<ans.size();++i){
            if(vis[i] || ans[i][2]==i){
                continue;
            }
            int cyclesize=0;
            int j=i;

            while(vis[j]!=true){
                vis[j]=true;
                j=ans[j][2];
                cyclesize++;
            }
            sw+=cyclesize-1;
        }
        return sw;
    }
};
