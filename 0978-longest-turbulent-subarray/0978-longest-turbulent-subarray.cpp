class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();

        bool isGreater=false;
        bool isSmaller=false;
        int ans=1;
        int len=1;

        for(int i =1 ;i<n;++i){
           if(arr[i-1]>arr[i]){
            if(isSmaller==true) len++;
            else len=2;
            isGreater=true;
            isSmaller=false;
           }
           else if(arr[i-1]<arr[i]){
            if(isGreater==true) len++;
            else len=2;
            isGreater=false;
            isSmaller=true;
           }

           else{
            len=1;
            isGreater=false;
            isSmaller=false;
           }
           ans=max(ans,len);
        }
        return ans;
    }
};