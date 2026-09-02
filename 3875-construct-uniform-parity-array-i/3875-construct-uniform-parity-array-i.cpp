class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        vector<int>nums2(n);
        int odd=0;
        int even=0;

        for(int i=0;i<n;++i){
          if(nums1[i]%2==0) even++;
          else odd++;
        }

        if(odd==even) return true;
        else if(odd>0 && even==0) return true;
         else if(even>0 && odd==0) return true;
          return true;
    }
};