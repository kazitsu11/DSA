class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();

        vector<int>arr1;
        vector<int>arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for(int i=2;i<n;++i){
            int k=arr1.size();
            int z=arr2.size();
          if(arr1[k-1]>arr2[z-1]){
            arr1.push_back(nums[i]);
          }
          else{
            arr2.push_back(nums[i]);
          }
        }

        int m=arr1.size();
        int j=arr2.size();
        vector<int>res;

        for(int i=0;i<m;++i){
            res.push_back(arr1[i]);
        }

        for(int i=0;i<j;++i){
            res.push_back(arr2[i]);
        }

        return res;
    }
};