class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int result=0;
        int presum=0;
        mp[0]=1;

        for(int i=0;i<n;++i){
            presum+=nums[i];
            if(mp.find(presum-k)!=mp.end()){
                result+=mp[presum-k];
            }
          mp[presum]++;
        }
        return result;
    }
};