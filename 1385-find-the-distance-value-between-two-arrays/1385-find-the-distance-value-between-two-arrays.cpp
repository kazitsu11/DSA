class Solution {
public:
bool check(int num,vector<int>&arr2,int d){
    for(int i=0;i<arr2.size();++i){
        if(abs(num-arr2[i])<=d){
            return true;
        }
    }
    return false;
}
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n=arr1.size();
        int count=0;

        for(int i=0;i<n;++i){
            if(check(arr1[i],arr2,d)==false){
                count++;
            }
        }
        return count;
    }
};