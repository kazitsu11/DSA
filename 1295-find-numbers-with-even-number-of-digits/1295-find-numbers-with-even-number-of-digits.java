class Solution {
    public int findNumbers(int[] nums) {
        int n = nums.length;
        int even=0;

        for (int a : nums) {
            int count=0;
            int temp = a;

            while (temp > 0) {
                int digit = temp % 10;
                count++;
                temp/=10;
            }
            if(count%2==0) even++;
        }
        return even;
    }
}