class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int fb=flowerbed.size();
       
         if(fb==1){
            if(flowerbed[0]==0) n--;
        }
        if(n<=0) return true;

         if(flowerbed[0]==0 && flowerbed[1]==0){
            flowerbed[0]=1;
            n--;
        }
        if(n<=0) return true;
        

        int i=1;
        while(i<fb){
            if(i+1<fb && flowerbed[i]==0 &&flowerbed[i+1]==0 &&  flowerbed[i-1]==0){
                flowerbed[i]=1;
                n--;
            }
            if(n==0) return true;
            ++i;
        }

     if(flowerbed[fb-1]==0 && flowerbed[i-2]==0){
      flowerbed[i-1]=1;
      n--;
     } 
        return n<=0?true:false;
    }
};