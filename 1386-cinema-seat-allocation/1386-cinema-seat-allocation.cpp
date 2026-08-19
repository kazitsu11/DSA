class Solution {
public:

 bool available(int seat,unordered_set<int>bookedSeat){
    if(bookedSeat.find(seat)==bookedSeat.end()) return true;
    return false;
 }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>>mp;

        for(auto& a:reservedSeats){
            int i=a[0];
            int j=a[1];

            mp[i].insert(j);
        }
        int result=(n-mp.size())*2;


        for(auto & a:mp){
            int row=a.first;
            unordered_set<int> &bookedSeat=a.second;

            bool groupA=available(2,bookedSeat) && available(3,bookedSeat) && available(4,bookedSeat) && available(5,bookedSeat);
            bool groupB=available(4,bookedSeat) && available(5,bookedSeat) && available(6,bookedSeat) && available(7,bookedSeat);
            bool groupC=available(6,bookedSeat) && available(7,bookedSeat) && available(8,bookedSeat) && available(9,bookedSeat);

            if(groupA && groupC) result+=2;
            else if(groupA || groupB || groupC) result+=1;

        }
        return result;
    }
};