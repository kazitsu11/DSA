class Solution {
    public int majorityElement(int[] nums) {
        HashMap<Integer,Integer>mp=new HashMap<>();
        int n=nums.length;

        for(int i=0;i<nums.length;++i){
            mp.put(nums[i],mp.getOrDefault(nums[i],0)+1);
        }

        for(int i=0;i<nums.length;++i){
            if(mp.get(nums[i])>n/2){
                return nums[i];
            }
        }
        return 0;
    }
}