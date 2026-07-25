class Solution {
public:
    int maxProduct(int n) {
        int digit;
        vector<int> ans;

        while (n > 0) {
            digit = n % 10;
            ans.push_back(digit);
            n = n / 10;
        }
       sort(ans.begin(),ans.end(),greater());
       
        return ans[0] * ans[1];
    }
};