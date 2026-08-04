class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        vector<int> lisdp(n, 1);
        int maxlis = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    int candidate = 1 + lisdp[j];
                    if (candidate > lisdp[i]) {
                        lisdp[i] = candidate;
                    }
                }
            }
        }

        vector<int> ldsdp(n, 1);
        int maxlds = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[i] > nums[j]) {
                    int candidate = 1 + ldsdp[j];
                    if (candidate > ldsdp[i]) {
                        ldsdp[i] = candidate;
                    }
                }
            }
        }
       
 int max_len=0;
       for(int i=0;i<n;++i){
        if(lisdp[i]>1 && ldsdp[i]>1){
            int mountainlength=lisdp[i]+ldsdp[i]-1;

             max_len=max(max_len,mountainlength);
        }
       }

       return n-max_len;
    }
};