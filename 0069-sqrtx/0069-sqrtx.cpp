class Solution {
public:
bool isSqrt(long long mid,int x){
    if(mid*mid<=x){
        return true;
    }
    return false;
}
    int mySqrt(int x) {
        int left=0;
        int right=x;
        int ans;

        while(left<=right){
            long long mid=left+(right-left)/2;
            if(isSqrt(mid,x)){
                 ans=mid;
                 left=mid+1;
            }
            else{
                right=mid-1;
            }

        }
        return ans;
    }
};