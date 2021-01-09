class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string word1Concat = "", word2Concat = "";
        
        for(auto word : word1) {
            word1Concat += word;
        }
        
        for(auto word : word2) {
            word2Concat += word;
        }
        
        return word1Concat == word2Concat;
    }
};