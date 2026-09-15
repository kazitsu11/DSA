class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mnm=*min_element(nums.begin(),nums.end());
        int mxm=*max_element(nums.begin(),nums.end());

        return gcd(mnm,mxm);
    }
};