class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int max_len=0;
       
       for(int right=0;right<n;++right){
        while(right<n && nums[right]==1){
            max_len=max(max_len,right-left+1);
            ++right;
        }
        left=right+1;
       }
       return max_len;
    }
};