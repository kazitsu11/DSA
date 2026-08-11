class Solution {
public:
    int longestMountain(vector<int>& arr) {

        int n = arr.size();
        int i = 1;
        vector<int> dp1(n, 1);
        vector<int> dp2(n, 1);

        if (n < 3) return 0;

        while (i < n) {
            if (arr[i] > arr[i - 1]) {
                dp1[i] = dp1[i - 1] + 1;
            }
            ++i;
        }

        int j = n - 2;
        while (j >= 0) {
            if (arr[j] > arr[j + 1]) {
                dp2[j] = dp2[j + 1] + 1;
            }
            --j;
        }
      
      int ans=0;

      for(int i=0;i<n;++i){
        if(dp1[i]>1 && dp2[i]>1){
            ans=max(ans,dp1[i]+dp2[i]-1);
        }
      }
        return ans ;
    }
};