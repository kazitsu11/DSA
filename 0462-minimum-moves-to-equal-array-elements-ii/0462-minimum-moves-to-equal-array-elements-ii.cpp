class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int mid=n/2;

        int left=0;
        int right=n-1;
        int op=0;

        while(left<=right){
          op+=abs(nums[mid]-nums[left]);
          op+=abs(nums[right]-nums[mid]);
          left++;
          right--;
        }
        return op;
    }
};