class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& inter) {
        int n = inter.size();
        sort(inter.begin(), inter.end(),
             [](vector<int>& a, vector<int>& b) { 
                if(a[0]==b[0]){
                    return a[1]>b[1];
                }
                return a[0] < b[0]; });

        int currStart = inter[0][0];
        int currEnd = inter[0][1];
        int count = 1;

        for (int i = 1; i < n; ++i) {
            int nextStart = inter[i][0];
            int nextEnd = inter[i][1];
            if (currStart > nextStart || currEnd < nextEnd) {
                count++;
                currStart = nextStart;
                currEnd = nextEnd;
            }
        }
        return count;
    }
};