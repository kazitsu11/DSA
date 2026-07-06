class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto & n:nums){
            pq.push(n);
        }
int remove=nums.size()-k;
while(remove--){
    pq.pop();
}
return pq.top();
    }
};