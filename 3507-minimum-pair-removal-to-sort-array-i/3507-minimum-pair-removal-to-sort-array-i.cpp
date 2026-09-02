class Solution {
public:
bool sorted(vector<long long>&a){
    for(int i=0;i+1<a.size();++i){
        if(a[i]>a[i+1]) return false;
    }
    return true;
}
    int minimumPairRemoval(vector<int>& nums) {
        vector<long long>a(nums.begin(),nums.end());
        int n=nums.size();
        int ops=0;

        while(!sorted(a)){
            int best=0;
          for(int i=1;i+1<a.size();++i){
            if(a[i]+a[i+1]<a[best]+a[best+1]) best=i;
          }
           a[best]=a[best]+a[best+1];
            a.erase(a.begin()+best+1);
            ops++;
        }
        return ops;
    }
};