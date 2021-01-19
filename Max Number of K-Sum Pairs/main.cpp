class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        int ans = 0;
        for (auto n:nums) {
            if (mp[k-n]) {
                mp[k-n]--;
                ans++;
            } 
            else mp[n]++;
        }
        return ans;
    }
};