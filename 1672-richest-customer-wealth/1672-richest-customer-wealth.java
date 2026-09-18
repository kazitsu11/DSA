class Solution {
    public int maximumWealth(int[][] accounts) {
        int n=accounts.length;
        int wealth=0;

        for(int i=0;i<n;++i){
         int total=0;
         int[]curr=accounts[i];
        for(int a:curr){
            total+=a;
        }
        wealth=Math.max(wealth,total);
        }
        return wealth;
    }
}