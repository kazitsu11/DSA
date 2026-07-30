class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int n=prices.size();
        int profit=0;

        for(int i=1;i<n;++i){
            if(buy>prices[i]){
                buy=prices[i];
            }
            profit=max(profit,abs(buy-prices[i]));
        }
        return profit;
    }
};