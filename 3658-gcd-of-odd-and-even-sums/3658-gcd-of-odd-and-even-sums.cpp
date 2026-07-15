class Solution {
public:
int gcd(int a,int b){
    if(b==0){
        return a;
    }

    if(a<b)
    swap(a,b); 

     return gcd(b,a%b);
}
    int gcdOfOddEvenSums(int n) {
        long long oddSum=1LL*n*n;
        long long evenSum=1LL *n*(n+1);
    
        return gcd(oddSum,evenSum);
    }
};