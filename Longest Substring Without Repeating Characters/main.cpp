class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int maxLen = 0, curLen = 0, start = 0, end = 0;
        vector<int> mp(256, 0);
        
        for(int end = 0; end < s.size(); end++) {
            
            if(mp[s[end]]) {
                start = max(mp[s[end]] + 1, start);
            }
            
            if(maxLen < (end - start + 1)) {
                maxLen = end - start + 1;
            }
            
            mp[s[end]] = end;
            
        }
        
        return maxLen;
    }
};