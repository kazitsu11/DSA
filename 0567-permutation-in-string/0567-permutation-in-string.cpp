class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        int l = 0;

        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;

        for (int i = 0; i < n1; ++i) {
            mp1[s1[i]]++;
        }

        while (n1 <= n2) {
            for (int i = l; i < n1; ++i) {
                mp2[s2[i]]++;
            }
            if (mp1 == mp2) {
                return true;
            }
            mp2.clear();
             l++;
             n1++;
        }
        return false;
    }
};