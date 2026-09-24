class Solution {
public:
int check(int n){
 int temp=n;
 int sum=0;
 while(temp>0){
    int digit=temp%10;
    sum+=digit;
    temp/=10;
 }
 return sum;
}
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();++i){
            if(check(nums[i])==i){
                return i;
            }
        }
        return -1;
    }
};