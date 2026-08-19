class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int> ans;

        for (auto& a : arr) {
            pq.push({abs(x - a),a});
        }

        for(int i=0;i<k;++i){
            int top=pq.top().second;
            pq.pop();
            ans.push_back(top);
        }

        sort(ans.begin(),ans.end());

        return ans;
    }
};