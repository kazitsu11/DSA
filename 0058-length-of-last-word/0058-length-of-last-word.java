class Solution {
    public int lengthOfLastWord(String s) {
        
        char[] arr=s.toCharArray();
        int len=0;
        int n=arr.length;
         
       for(int i=n-1;i>=0;--i){
        if(arr[i]==' ') continue;
        while(i>=0 && arr[i]!=' '){
            len++;
            --i;
        }
        break;
       }
        return len;
    }
}