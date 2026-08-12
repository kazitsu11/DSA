class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;

        for (auto& a : s) {
            mp1[a]++;
        }
        for (auto& a : t) {
            mp2[a]++;
        }

        if(mp1==mp2) return true;
        return false;
    }
};