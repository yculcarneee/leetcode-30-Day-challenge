class Solution {
public:
    int countVowelStrings(int n) {
        int res = 0, sum = 0;
        for (int i = 1; i <= n + 1; ++i) {
            sum += i * (i + 1) / 2;
            res += sum;
        }
        return res;        
    }
};