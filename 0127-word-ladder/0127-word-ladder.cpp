class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());

        if(!st.count(endWord)) return 0;

        queue<string>q;
        q.push(beginWord);
        st.erase(beginWord);
        int steps=1;

        while(!q.empty()){
            int p=q.size();
            while(p--){
                string curr=q.front();
                q.pop();

                if(curr==endWord) return steps;

                for(int i=0;i<curr.size();++i){
                    char original=curr[i];
                    for(char c='a';c<='z';++c){
                        if(c==original) continue;
                        curr[i]=c;

                        if(st.count(curr)){
                            q.push(curr);
                            st.erase(curr);
                        }
                    }
                    curr[i]=original;
                }
            }
            steps++;
        }
        return 0;
    }
};