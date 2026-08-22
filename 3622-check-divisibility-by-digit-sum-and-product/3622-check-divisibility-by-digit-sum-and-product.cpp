class Solution {
public:
    bool checkDivisibility(int n) {
        int temp=n;
        int dsum=0;
        int psum=1;
        while(temp>0){
            int digit=temp%10;
            dsum+=digit;
            psum*=digit;
           temp/=10;
        }
        int total=dsum+psum;
        if(n%total==0) return true;
        return false;
    }
};