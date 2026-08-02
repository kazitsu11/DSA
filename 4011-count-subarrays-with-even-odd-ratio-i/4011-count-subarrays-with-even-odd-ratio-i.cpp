class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        int odd = 0;
        int even = 0;
        int valid = 0;

        for (int i = 0; i < n; ++i) {
            odd = 0;
            even = 0;
            for (int j = i ;j < n; ++j) {
                if (nums[j] % 2 != 0)
                    odd++;
                else
                    even++;   
                
                if (odd > 0) {
                    double c=(double)even / odd;
                    double d=(double)a/b;
                    if ( c<=d) {
                        // ratio.push_back(even/odd);
                        valid++;
                    }
                }
            }
        }
        return valid;
    }
    };