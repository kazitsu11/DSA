class Solution {
public:
    bool isHappy(int n) {
        int sum = n;
        unordered_set<int> st;
        while (sum != 1) {
            if (st.count(sum)) return false;
            st.insert(sum);
            int temp = sum;
            sum = 0;
            while (temp > 0) {
                int digit = temp % 10;
                sum += digit * digit;
                temp /= 10;
            }
        }
        return true;
    }
};