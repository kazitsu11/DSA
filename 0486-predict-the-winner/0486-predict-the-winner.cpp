class Solution {
public:
    int solve(int i, int j, vector<int>& nums) {
        if (i == j) return nums[i];

        int ans=INT_MIN;
            int take_left = nums[i]-solve(i+1,j,nums);
            int take_right = nums[j]-solve(i,j-1,nums);
            ans = max({ans, take_left, take_right});

            return ans;
   
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(solve(0,n-1,nums)>=0){
            return true;
        }
        return false;
    }
};