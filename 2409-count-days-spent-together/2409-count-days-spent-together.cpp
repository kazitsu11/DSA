class Solution {
public:
int getDay(string date){
    int month=stoi(date.substr(0,2));
    int day=stoi(date.substr(3,2));

    int days[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total=day;

    for(int i=0;i<month;++i){
        total+=days[i];
    }
    return total;
}
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arr_A=getDay(arriveAlice);
        int arr_B=getDay(arriveBob);
        int lea_A=getDay(leaveAlice);
        int lea_B=getDay(leaveBob);

        
        int left=max(arr_A,arr_B);
        int right=min(lea_A,lea_B);
        if(right<left) return 0;
        return right-left+1;
        
    }
};