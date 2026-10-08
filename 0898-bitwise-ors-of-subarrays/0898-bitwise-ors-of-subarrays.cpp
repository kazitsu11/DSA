class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>res,curr,next;

        for(auto& a:arr){
            next.clear();
            next.insert(a);

            for(int x:curr){
                next.insert(x|a);
            }
            curr=next;
            res.insert(curr.begin(),curr.end());
        }
        return res.size();
    }
};