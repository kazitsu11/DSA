class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;

        for(auto& a:nums){
            pq.push(a);
        }
        int top=0;
        while(k--){
             top=pq.top();
            pq.pop();
        }
        return top;
    }
};