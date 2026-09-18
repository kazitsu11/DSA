class Solution {
    public int firstUniqChar(String s) {
        int n=s.length();
        char[] arr= s.toCharArray();
        HashMap<Character,Integer>mp=new HashMap<>();
        for(int i=0;i<n;++i){
        mp.put(arr[i],mp.getOrDefault(arr[i],0)+1);
        }

        for(int i=0;i<n;++i){
            if(mp.get(arr[i])==1){
                return i;
            }
        }
        return -1;
    }
}