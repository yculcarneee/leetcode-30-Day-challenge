class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        set<string> wordListSet(wordList.begin(), wordList.end());
        
        if(wordListSet.find(endWord) == wordListSet.end()) {
            return 0;
        }
        
        int res = 1;
        
        queue<string> q;
        q.push(beginWord);
        
        while(!q.empty()) {
            int n = q.size();
            
            for(int i = 0; i < n; i++) {
                string word = q.front();
                q.pop();
                
                for(int j = 0; j < word.size(); j++) {
                    char ch = word[j];
                    
                    for(char c = 'a'; c <= 'z'; c++) {
                        word[j] = c;
                        
                        if(word == endWord) {
                            return res + 1;
                        }
                        
                        if(wordListSet.find(word) != wordListSet.end()) {
                            q.push(word);
                            wordListSet.erase(word);
                        }
                    }
                    
                    word[j] = ch;
                }
            }
            
            res++;
        }
        
        return 0;
    }
};