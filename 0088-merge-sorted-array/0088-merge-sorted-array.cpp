class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    
        int right=m;
        for(auto& a:nums2){
            nums1[right]=a;
            right++;
        }

      sort(nums1.begin(),nums1.end());
    }
};