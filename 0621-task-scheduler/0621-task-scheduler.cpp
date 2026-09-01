class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(auto&a:tasks){
            freq[a-'A']++;
        }

        priority_queue<int>pq;
        for(auto&a:freq){
            if(a>0) pq.push(a);
        }
        queue<pair<int,int>>cooldown;
        int time=0;
        while(!pq.empty() || !cooldown.empty()){
            time++;
            if(!pq.empty()){
                int cnt=pq.top();
                pq.pop();
                if(--cnt>0){
                    cooldown.push({cnt,time+n});
                }
            }
            if(!cooldown.empty() && cooldown.front().second==time){
               pq.push(cooldown.front().first);
               cooldown.pop();
            }
        }
        return time;
    }
};