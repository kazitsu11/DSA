class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxsum=nums[0];
        int bestsum=nums[0];

        for(int i=1;i<n;++i){
           maxsum=max(nums[i],maxsum+nums[i]);
           bestsum=max(bestsum,maxsum);
        }
        return bestsum;
    }
};