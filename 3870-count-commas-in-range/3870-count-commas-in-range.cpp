class Solution {
public:
    int countCommas(int n) {
        int size;
        int curr = 1;
        int comma=0;
        while (curr <= n) {
             size = 0;
             int temp=curr;
            while (temp > 0) {
                int digit = temp % 10;
                size++;
                temp = temp / 10;
            }
            if (size > 3) {
               comma+=(size-1)/3;
            }
          curr++;
        }
        return comma;
    }
};