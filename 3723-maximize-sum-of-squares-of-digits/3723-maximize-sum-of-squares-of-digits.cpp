class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        string ans = "";
        int pos=num;
        while (sum > 0 && pos--) {
            int digit = min(9, sum);
            sum -= digit;
            ans += to_string(digit);
        }
        if (sum == 0) {
            while (ans.size() != num) {
                ans += "0";
            }
            return ans;
        }
        return "";
    }
};