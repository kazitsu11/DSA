class Solution {
public:

    void solve(int i,
               vector<string>& strs,
               vector<string>& group,
               vector<vector<string>>& ans,
               vector<array<int,26>>& freq,
               vector<bool>& vis) {

        int n = strs.size();

        // Put current string in its group
        group.push_back(strs[i]);
        vis[i] = true;

        // Find all anagrams
        for(int j = i + 1; j < n; j++) {

            if(vis[j])
                continue;

            if(freq[i] == freq[j]) {

                group.push_back(strs[j]);
                vis[j] = true;
            }
        }

        ans.push_back(group);
    }


    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n = strs.size();

        vector<vector<string>> ans;
        vector<bool> vis(n, false);

        // Calculate frequency of EVERY string only once
        vector<array<int,26>> freq(n);

        for(int i = 0; i < n; i++) {

            freq[i].fill(0);

            for(char c : strs[i]) {
                freq[i][c - 'a']++;
            }
        }

        // Your original idea:
        // pick an unvisited string and find its anagrams
        for(int i = 0; i < n; i++) {

            if(vis[i])
                continue;

            vector<string> group;

            solve(i, strs, group, ans, freq, vis);
        }

        return ans;
    }
};