class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        
        for(auto & a:stones){
            pq.push(a);
        }

        while(!pq.empty() && pq.size()>1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();

            if(x==y) continue;
            else{
                pq.push(abs(x-y));
            }
        }
        if(pq.empty()) return 0;
        return pq.top();
    }
};