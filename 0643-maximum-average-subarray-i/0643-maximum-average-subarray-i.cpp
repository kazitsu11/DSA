class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();

        int currsum=0;
        int maxsum=INT_MIN;

        for(int i=0;i<k;++i){
            currsum+=nums[i];
        }
        maxsum=max(maxsum,currsum);
        for(int j=k;j<n;++j){
            currsum=currsum-nums[j-k]+nums[j];
            maxsum=max(maxsum,currsum);
        }
        return (double)maxsum/k;
    }
};