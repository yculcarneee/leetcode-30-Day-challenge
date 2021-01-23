class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> word1Freq(26, 0), word2Freq(26, 0);
        vector<bool> word1Present(26, false), word2Present(26, false);
        
        for(char c : word1) {
            word1Freq[c - 'a']++;
            word1Present[c - 'a'] = true;
        }
        
        for(char c : word2) {
            word2Freq[c - 'a']++;
            word2Present[c - 'a'] = true;
        }
        
        sort(word1Freq.begin(), word1Freq.end());
        sort(word2Freq.begin(), word2Freq.end());
        
        if(word1Freq == word2Freq and word1Present == word2Present) {
            return true;
        }
        
        return false;
    }
};