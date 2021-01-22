class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) {
            return s;
        }
        
        int maxIdx = 0, maxLen = 1, start, end, i = 0;
        
        while(i < s.size()) {
            int start = i, end = i;
            
            while(end + 1 < s.size() and s[end] == s[end + 1]) {
                end++;
            }
            
            i = end + 1;
            
            while(start - 1 >= 0 and end + 1 < s.size() and s[start - 1] == s[end + 1]) {
                start--;
                end++;
            }
            
            int curLen = end - start + 1;
            
            if(curLen > maxLen) {
                maxIdx = start;
                maxLen = curLen;
            }
        }
        
        return s.substr(maxIdx, maxLen);
    }
};