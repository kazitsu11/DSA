class Solution {
public:
bool canFinish(vector<int>&piles,int h,int k){
    int n=piles.size();
    int hours=0;
    for(int i=0;i<n;i++){
        hours+=(piles[i]+k-1)/k;
    }
    if(hours<=h){
        return true;
    }
    else return false;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        while(left<right){
            int mid=left+(right-left)/2;
            if(canFinish(piles,h,mid)){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};