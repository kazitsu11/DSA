class Solution {
public:
bool isDiv(int n,int t){
    int temp=n;
    int prod=1;
    while(temp>0){
        int digit=temp%10;
        prod*=digit;
        temp=temp/10;
    }
    if(prod%t==0){
        return true;
    }
    return false;
}
    int smallestNumber(int n, int t) {
        
        int k=1;

        while(k>0){
            if(isDiv(n,t)){
                k--;
            }
            else{
                n++;
            }
        }
        return n;
    }
};