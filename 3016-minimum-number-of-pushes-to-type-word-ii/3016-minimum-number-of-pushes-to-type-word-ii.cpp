class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);

        int n=word.length();

        for(char c:word){
            freq[c-'a']++;
        }

        sort(freq.begin(),freq.end(),greater<int>());
        int push=0;

        for(int i=0;i<26;++i){
            if(freq[i]==0){
                continue;
            }
            int cost=(i/8)+1;

            push+=freq[i]*cost;
        }
        return push;
    }
};