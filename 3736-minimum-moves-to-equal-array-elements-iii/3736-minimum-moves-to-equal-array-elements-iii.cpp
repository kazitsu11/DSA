class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mid=n/2;

        int left=0;
        int right=n-1;
         
        int op=0;
        while(left<=right){
         op+=nums[right]-nums[left];
         left++;
        }
        return op;
    }
};