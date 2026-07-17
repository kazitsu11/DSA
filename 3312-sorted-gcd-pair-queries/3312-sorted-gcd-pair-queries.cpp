class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> divFreq(max_val + 1, 0);

        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            for (int j = 1; j * j <= num; ++j) {
                if (num % j == 0) {
                    divFreq[j]++;
                    if (num / j != j) {
                        divFreq[num / j]++;
                    }
                }
            }
        }

        vector<long long>pairGcd(max_val+1,0);
        for(int g=max_val;g>=1;--g){
            long long count=divFreq[g];
            pairGcd[g]=count*(count-1)/2;

            for(int mult=2*g;mult<=max_val;mult+=g){
                pairGcd[g]-=pairGcd[mult];
            }
        }

        vector<long long> prefixCountGcd(max_val+1,0);
        for(int g=1;g<max_val+1;++g){
            prefixCountGcd[g]=prefixCountGcd[g-1]+pairGcd[g];
        }

        vector<int>result;
          for(long long idx:queries){
            int l=1;
           int r=max_val;
            int temp=max_val;

            while(l<=r){
                int mid=l+(r-l)/2;

                if(prefixCountGcd[mid]>idx){
                    temp=mid;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            result.push_back(temp);
          }
       return result;
    }
};