class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while(!q.empty()){
            string word = q.front().first;
            int path = q.front().second;
            q.pop();
            if(word==endWord)
            return path;

            for(int i=0;i<beginWord.size();i++){
                char original = word[i];
                for(char ch = 'a';ch <= 'z';ch++){
                    word[i]=ch;
                    if(s.find(word) != s.end()){
                        s.erase(word);
                        q.push({word, path+1});
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};