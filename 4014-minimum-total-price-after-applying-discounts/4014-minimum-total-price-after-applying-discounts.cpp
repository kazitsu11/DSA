class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end(),greater<int>());
        sort(discounts.begin(),discounts.end(),greater<int>());

        int n=prices.size();
        int m=discounts.size();

        int i=0;
        int j=0;
        double sum=0;

        while(i<n){
            double price=prices[i];
            if(j<m){
               price=price*(100-discounts[j])/100;
               ++j;
            }
            sum+=price;
            ++i;
        }
        return sum;
    }
};