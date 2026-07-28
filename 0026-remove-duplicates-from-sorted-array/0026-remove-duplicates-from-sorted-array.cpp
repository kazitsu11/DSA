class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int slow=0;
        int fast=1;

        while(fast<n){
            if(nums[slow]!=nums[fast]){
                swap(nums[slow+1],nums[fast]);
               slow++;
            }
            fast++;
        }
        return slow+1;
    }
};