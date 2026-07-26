class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int maxprod=nums[0];
        int n=nums.size();
        sort(nums.begin(),nums.end(),greater<int>());

        int mnmprod;
        int mxmprod;
        
         
  mnmprod=nums[n-1]*nums[n-2]*nums[0];

  mxmprod=nums[0]*nums[1]*nums[2];
        return max(mnmprod,mxmprod);
    }
};