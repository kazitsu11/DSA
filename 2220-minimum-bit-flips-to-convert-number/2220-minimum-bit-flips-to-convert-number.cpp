class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorres=start^goal;
        int count=0;
        
        int temp=xorres;
        while(temp>0){
         int digit=temp%2;
          if(digit==1) count++;
          temp/=2;
        }
        return count;
    }
};