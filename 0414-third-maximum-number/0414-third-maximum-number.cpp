class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long largest=LLONG_MIN;
        long long second=LLONG_MIN;
        long long third=LLONG_MIN;

        for(auto& a:nums){
            if(a>largest){
                third=second;
                second=largest;
                largest=a;
            }
            else if(a>second && a!=largest){
                third=second;
                second=a;
            }
           else if(a>third && a!=second && a!=largest){
                third=a;
            }
        }
        if(third!=LLONG_MIN) return third;
        return largest;
    }
};