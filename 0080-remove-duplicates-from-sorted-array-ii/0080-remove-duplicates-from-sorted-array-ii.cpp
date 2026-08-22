class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int check=2;

        if(nums.size()<=2) return nums.size();

        for(int i=2;i<nums.size();++i){
            if(nums[i]!=nums[check-2]){
                 nums[check]=nums[i];
                 check++;
            }
        }
        return check;
    }
};