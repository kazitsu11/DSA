class Solution {
public:
bool ispeak(int mid,vector<int>&arr,int n){
    if(mid>0 && mid<n-1 && arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
        return true;
    }
    return false;
}
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        int ans;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(ispeak(mid,arr,n)){
               return mid;
            }
            else if(arr[mid]<arr[mid+1]){
                low=mid+1;
            }
            else{
              high=mid-1;
            }
        }
        return low;
    }
};