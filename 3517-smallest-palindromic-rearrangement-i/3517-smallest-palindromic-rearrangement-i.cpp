class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        string left;
        string middle;

        map<char, int> mp;

        for (char c : s) {
            mp[c]++;
        }

        int odd = 0;

        for (auto& a : mp) {
            if (a.second % 2 != 0) {
                odd++;
            }
        }

        for (auto& a : mp) {
            int freq = a.second;
            if (n % 2 != 0 && odd == 1) {
                for (int i = 0; i < freq / 2; ++i) {
                    left.push_back(a.first);
                }
                if (freq % 2 != 0) {
                    middle.push_back(a.first);
                }
            }

            else if (n % 2 == 0 && odd == 0) {
                for (int i = 0; i < freq / 2; ++i) {
                    left.push_back(a.first);
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + middle + right;
    }
};