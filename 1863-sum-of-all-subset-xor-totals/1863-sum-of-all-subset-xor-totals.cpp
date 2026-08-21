class Solution {
public:
int sum=0;
void backtrack(int idx,vector<int>&nums,int xorvalue){
    sum+=xorvalue;
    for(int i=idx;i<nums.size();++i){
        backtrack(i+1,nums,xorvalue^nums[i]);
    }
}
    int subsetXORSum(vector<int>& nums) {
        int xorvalue=0;
        backtrack(0,nums,xorvalue);
        return sum;
    }
};