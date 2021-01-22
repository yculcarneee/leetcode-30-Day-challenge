class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        
        map<char, char> mp ={{')', '('}, {'}','{'}, {']','['}};
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
            }
            else {
                if(stk.empty() || stk.top() != mp[s[i]]) {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};