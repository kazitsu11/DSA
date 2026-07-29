class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos,
                vector<int>& rowCosts, vector<int>& colCosts) {
        int n = rowCosts.size();
        int m = colCosts.size();

        int r1 = startPos[0];
        int c1 = startPos[1];

        int r2 = homePos[0];
        int c2 = homePos[1];
        int ans = 0;

        if (r1 < r2) {
            for (int i = r1 + 1; i <= r2; ++i) {
                ans += rowCosts[i];
            }
        }
         else {
            for (int i = r1 - 1; i >= r2; i--) {
                ans += rowCosts[i];
            }
        }

        if (c1 < c2) {
            for (int j = c1 + 1; j <= c2; ++j) {
                ans += colCosts[j];
            }
        } 
        else {
            for (int j = c1 - 1; j >= c2; j--) {
                ans += colCosts[j];
            }
        }

        return ans;
    }
};