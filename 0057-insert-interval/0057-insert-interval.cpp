class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());

        int currStart=intervals[0][0];
        int currEnd=intervals[0][1];
        vector<vector<int>>ans;

        for(int i=0;i<intervals.size();++i){
          int nextStart=intervals[i][0];
          int nextEnd=intervals[i][1];

          if(nextStart<=currEnd){
            currStart=min(currStart,nextStart);
            currEnd=max(currEnd,nextEnd);
          }
          else{
            ans.push_back({currStart,currEnd});
            currStart=nextStart;
            currEnd=nextEnd;
          }
        }
        ans.push_back({currStart,currEnd});
        return ans;
    }
};