class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
         int mnm=*min_element(nums1.begin(),nums1.end());

         if(mnm%2==1) return true;
         
         int odd=0;
         for(int i=0;i<nums1.size();++i){
            if(nums1[i]%2!=0) odd++;
         }
         if(odd==0) return true;
         return false;
    }
};