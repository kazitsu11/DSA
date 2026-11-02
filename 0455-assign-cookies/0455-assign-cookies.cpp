class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end(),greater<int>());
        sort(s.begin(),s.end(),greater<int>());

        int n=g.size();
        int m=s.size();
        int i=0;
        int j=0;
        int count=0;
        while(i<n && j<m){
            if(s[j]>=g[i]){
                count++;
                j++;
            }
            i++;
        }
        return count;
    }
};