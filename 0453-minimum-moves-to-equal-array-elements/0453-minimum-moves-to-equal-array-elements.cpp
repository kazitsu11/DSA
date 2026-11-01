class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int sum =0;
        for(auto&a:nums){
            sum+=a;
        }
        int mnm=*min_element(nums.begin(),nums.end());

        return sum-n*mnm;
    }
};