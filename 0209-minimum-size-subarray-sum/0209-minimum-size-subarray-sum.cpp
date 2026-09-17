class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int total=0;

        for(auto& a:nums){
            total+=a;
        }
        if(total<target) return 0;

        total=0;
        int mnmlen=INT_MAX;
        int left=0;

        for(int right=0;right<n;++right){
            total+=nums[right];
            while(total>=target){
              mnmlen=min(mnmlen,right-left+1);
              total-=nums[left];
              left++;
            }
        }
        return mnmlen;
    }

};