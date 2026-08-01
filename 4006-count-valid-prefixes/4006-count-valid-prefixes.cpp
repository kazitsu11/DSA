class Solution {
public:
    int countValidPrefixes(string s) {
        int n = s.size();
        int one_count = 0;
        int zero_count = 0;
        int valid = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                zero_count++;
            } else if (s[i] == '1') {
                one_count++;
            }

            if(abs(one_count-zero_count)==1 || abs(one_count -zero_count)==0) valid++;
        }
        return valid;
    }
};