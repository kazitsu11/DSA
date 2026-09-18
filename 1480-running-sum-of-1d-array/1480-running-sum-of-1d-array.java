class Solution {
    public int[] runningSum(int[] nums) {
        int n=nums.length;
        int []arr=new int [n];
        int presum=0;

        for(int i=0;i<n;++i){
            presum+=nums[i];
            arr[i]=presum;
        }
        return arr;
    }
}