class Solution {
public:
long long gcd(int a,int b){
    if(b==0){
        return a;
    }
    if(a<b){
        swap(a,b);
    }
    return gcd(b,a%b);
}
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>mx(n);
        vector<int>pref(n);
        
        int curr=nums[0];
        for(int i=0;i<n;++i){
            curr=max(curr,nums[i]);
            mx[i]=curr;
        }
        for(int i=0;i<n;++i){
            pref[i]=gcd(nums[i],mx[i]);
        }

        sort(pref.begin(),pref.end());

        int left=0;
        int right=n-1;
        long long count=0;
        while(left<right){
         count+= gcd(pref[left],pref[right]);
         left++;
         right--;
        }
        return count;
    }
};