class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>arr1;
        vector<int>arr2;
       int k=2*n;
        for(int i=0;i<k/2;++i){
          arr1.push_back(nums[i]);
        }
        for(int j=k/2;j<k;++j){
            arr2.push_back(nums[j]);
        }
        vector<int>ans;
        int left=0;
        int right=0;
        while(left<arr1.size() && right<arr2.size()){
          ans.push_back(arr1[left++]);
          ans.push_back(arr2[right++]);
          
        }
        return ans;
    }
};