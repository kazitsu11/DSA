class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int>left(n);

        left[0]=nums[0];
        for(int i=1;i<n;++i){
            left[i]=max(left[i-1],nums[i]);
        }

        vector<int>right(n);
        right[n-1]=nums[n-1];
        for(int i=n-2;i>=0;--i){
          right[i]=min(nums[i],right[i+1]);
        }

        int small=1e9;
        for(int i=0;i<n;++i){
            if( left[i]-right[i]<=k){
              small=min(small,i);
            }
        }
        if(small==1e9) return -1;
        return small;
    }
};