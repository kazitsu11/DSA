class Solution {
public:
 bool ismid(int mid,vector<int>& weights, int days){
    int sum=0;
    int daysneeded=1;
    for(auto& a:weights){
        sum+=a;
        if(sum<=mid){
         continue;
        }
        else{
            daysneeded++;
            sum=a;
        }
    }
    return daysneeded<=days;
 }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int sum=0;
        for(auto& a:weights){
            sum+=a;
        }
        int high=sum;
        while(low<=high){
          int mid=low+(high-low)/2;
          if(ismid(mid,weights,days)){
            high=mid-1;
          }
          else{
            low=mid+1;
          }
        }
        return low;
    }
};