class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int  curr=nums[0];
        int mxm=nums[0];
        int mnm=nums[0];
        int minbest=nums[0];
        int maxbest=nums[0];
        int ans;
        int n=nums.size();
        if(n==1){
            return abs(nums[0]);
        }
        for(int i=1;i<n;++i){
         mxm=max(nums[i],mxm+nums[i]);
         mnm=min(nums[i],mnm+nums[i]);
           
            maxbest=max(maxbest,mxm);
             minbest=min(minbest,mnm);
           
        }
         ans=max(abs(minbest),abs(maxbest));
        return ans;
    }
};