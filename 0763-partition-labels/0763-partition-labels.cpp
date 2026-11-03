class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        unordered_map<char,int>last;
        vector<int>arr;

        for(int i=0;i<n;++i){
            last[s[i]]=i;
        }

        int left=0;
        int end=0;
        for(int right=0;right<n;++right){
             end=max(end,last[s[right]]);
            if(right==end){
             arr.push_back(end-left+1);
             left=right+1;
            }
        }
        return arr;
    }
};