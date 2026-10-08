class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long>left(n);
        vector<long long>right(n);
        long long front=0;
        long long back=0;
        for(int i=0;i<n;++i){
             front+=nums[i];
            left[i]+=front;
        }

        for(int i=n-1;i>=0;--i){
             back+=nums[i];
            right[i]+=back;
        }

        int split=0;
        for(int i=0;i<n;++i){
            if(i+1<n && left[i]>=right[i+1]){
              split++;
            }
        }
        return split;
    }
};