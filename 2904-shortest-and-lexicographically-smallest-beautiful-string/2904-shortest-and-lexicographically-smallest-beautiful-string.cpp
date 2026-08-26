class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int ones = 0;

        int left = 0;
        int right = 0;
        int len;
        string curr = string(101,'1');
        int cnt=count(s.begin(),s.end(),'1');
        if(cnt<k) return "";

        for (int right = 0; right < n; ++right) {
            if (s[right] == '1') {
                ones++;
            }
            while (ones == k) {
                len = right - left + 1;
                string next = s.substr(left, len);
                if ((next < curr && next.size()==curr.size()) || next.size()<curr.size()) {
                    curr = next;
                }
                 if (s[left] == '1') {
                    ones--;
                }
                left++;
            }
        }
        return curr;
    }
};