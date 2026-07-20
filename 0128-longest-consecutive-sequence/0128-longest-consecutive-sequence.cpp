class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size()==0){
            return 0;
        }

        int n=nums.size();
        int count=0;
        int ans=0;

        for(int i=0;i<n-1;++i){
            if(nums[i]==nums[i+1]){
                continue;
            }
            if(nums[i]+1==nums[i+1]){
                count++;
            }
            else{
                count=0;
            }
            ans=max(ans,count);
        }
       return ans+1;
    }
};