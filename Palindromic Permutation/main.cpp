class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<char> freq(256, 0);
        int odd = 0;
        
        for(char c : s) {
            freq[c]++;
        }
        
        for(int i = 0; i < 256; i++) {
            if(freq[i] % 2 != 0) {
                odd++;
            }
            
            if(odd > 1) {
                return false;
            }
        }
        
        return true;
    }
};