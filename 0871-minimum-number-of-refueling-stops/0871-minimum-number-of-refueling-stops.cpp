class Solution {
public:
    int minRefuelStops(int target, int startFuel,vector<vector<int>>& stations) {

        priority_queue<int> pq;
        int stops = 0;
        int totalfuel = startFuel;
        int i = 0;
        int n = stations.size();
        while (totalfuel < target) {
            while (i < n && totalfuel >= stations[i][0]) {
                pq.push(stations[i][1]);
                i++;
            }
            if (pq.empty()) {
                return -1;
            }
            totalfuel += pq.top();
            pq.pop();
            stops++;
        }
        return stops;
    }
};