class Solution {
public:
 bool isVowel(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return true;
    return false;
 }
    int maxVowels(string s, int k) {
        int n=s.size();
        int left=0;
        int mxm=0;
        int count=0;

        for(int right=0;right<n;++right){

            if(isVowel(s[right])){
                count++;
            }
            while(right-left+1==k){
              mxm=max(mxm,count);
              if(isVowel(s[left])) count--;
              left++;
            }
        }
        return mxm;
    }
};