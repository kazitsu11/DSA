class Solution {
public:
bool eat(int k,vector<int>& piles, int h){
    int n= piles.size();
    long long hours=0;
    for(int i=0;i<n;++i){
    hours=hours+(piles[i]+k-1)/k;
    }
    if(hours<=h){
        return true;
    }
    return false;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());

        while(low<=high){
            int mid=low+(high-low)/2;
            if(eat(mid,piles,h)){
                high=mid-1;
            }
            else{
               low=mid+1;
            }
        }
        return low;
    }
};