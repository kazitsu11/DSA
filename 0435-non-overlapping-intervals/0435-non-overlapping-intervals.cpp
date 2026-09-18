class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        int n=intervals.size();
        int count=0;

        int currStart=intervals[0][0];
        int currEnd=intervals[0][1];

        for(int i=1;i<n;++i){
            int nextStart=intervals[i][0];
            int nextEnd=intervals[i][1];

            if(currEnd>nextStart){
             count++;
             currEnd=min(currEnd,nextEnd);
            }
            else{
            currEnd=nextEnd;
            currStart=nextStart;
            }
        }
      return count;
    }
};