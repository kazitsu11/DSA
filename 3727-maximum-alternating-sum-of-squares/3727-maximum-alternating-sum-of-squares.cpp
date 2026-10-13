class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(auto& a:nums){
            if(a<0){
                a=-a;
            }
        }
         sort(nums.begin(),nums.end());
         int n=nums.size();
         long long sum=0;
         int left=0;
         int right=n-1;

         while(left<right){
            sum+=nums[right] * nums[right] - nums[left] * nums[left];
            left++;
            right--;
         }
         if(n%2!=0 && left==right){
            sum+=nums[left]*nums[left];
         }
         return sum;
    }
};