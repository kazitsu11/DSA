class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for (auto& a : s) {
            mp[a]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto& a : mp) {
            int ch = a.first;
            int freq = a.second;
            if (freq > 0)
                pq.push({freq, ch});
        }

        queue<vector<int>> cooldown;
        string t;
        int time = 0;

        while (!pq.empty() || !cooldown.empty()) {
            time++;

            if (!cooldown.empty() && cooldown.front()[1] == time) {
                auto curr = cooldown.front();
                int first = curr[0];
                int second = curr[1];
                char third = curr[2];
                pq.push({first,third});
                    cooldown.pop();
            }
            
            if (!pq.empty()) {
                    int cnt = pq.top().first;
                    char ch = pq.top().second;
                    pq.pop();
                    t.push_back(ch);

                    if (--cnt > 0) {
                        cooldown.push({cnt, time + 2, ch});
                    }
            } else
                return "";
            }
            return t;
        }
    };