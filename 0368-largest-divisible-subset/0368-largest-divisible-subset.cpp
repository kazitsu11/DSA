class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());

        vector<int>dp(n,1);
        vector<int>parent(n,-1);
        int maxlen=1;
        int start=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(nums[i]%nums[j] ==0 || nums[j] % nums[i]==0){
                    int candidate=1+dp[j];
                    if(candidate>dp[i]){
                        dp[i]=candidate;
                        parent[i]=j;
                    }
                }
            }
           if(dp[i]>maxlen){
             maxlen=dp[i];
             start=i;
           }
        }


        vector<int>ans;
        int curr=start;
        while(curr!=-1){
            ans.push_back(nums[curr]);
            curr=parent[curr];
        }
        return ans;
    }
};