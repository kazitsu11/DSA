class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int left=0;
        int fb=flowerbed.size();

        while(left<fb){
            bool leftempty=(left==0||flowerbed[left-1]==0);
            bool rightempty=(left==fb-1||flowerbed[left+1]==0);

            if(flowerbed[left]==0 && leftempty && rightempty){
                flowerbed[left]=1;
                n--;
            }
            left++;
        }
        return n<=0;
    }
};