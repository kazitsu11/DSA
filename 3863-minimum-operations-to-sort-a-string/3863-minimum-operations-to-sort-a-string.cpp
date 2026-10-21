class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string b = s;
        sort(b.begin(), b.end());
        char min = *min_element(s.begin(), s.end());
        char max = *max_element(s.begin(), s.end());

        if (s == b) return 0;
        if (n < 3) return -1;

        if (s[0] == min || s[n - 1] == max) return 1;
         
        for (int i = 1; i < n - 1; ++i) {
            if (s[i] == min || s[i] == max) return 2;
        }
        return 3;
    }
};
