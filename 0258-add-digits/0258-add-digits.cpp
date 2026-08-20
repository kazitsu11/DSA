class Solution {
public:
    int addDigits(int num) {
        
        if(num<10) return num;
        int sum=0;
        while(num>9){
            int temp=num;
             sum=0;
            while(temp>0){
            int digit=temp%10;
            sum+=digit;
            temp=temp/10;
        }
        num=sum;
    }
        return sum;
    }
};