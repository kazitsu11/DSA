class Solution {
public:
    bool isDiv(int mid, int t) {
        // vector<int> ans;
        int prod = 1;
        int temp = mid;
        while (temp > 0) {
            int digit = temp % 10;
            //ans.push_back(digit);
            prod*=digit;
            temp = temp / 10;
        }
        if (prod % t == 0) {
            return true;
        }
        return false;
    }
    int smallestNumber(int n, int t) {

        int low = n;
        int high = n + t;
        int ans;

        while (low <= high) {
            int mid = low;
            if (isDiv(mid,t)) {
                 ans = mid;
                high=mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
};