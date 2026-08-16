class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int totalsum=0;
        
        for(auto& a:nums){
            totalsum+=a;
        }

        if(totalsum<target) return 0;

         int left=0;
         int currlen=0;
         int minlen=INT_MAX;
         int sum=0;
        
        for(int right=0;right<n;++right){
            sum+=nums[right];
          while(right<n && sum>=target){
            currlen=right-left+1;
          minlen=min(minlen,currlen);
            sum-=nums[left];
            left++;
          }
        }
        return minlen;
    }
};