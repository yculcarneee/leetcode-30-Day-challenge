class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, n = nums.size();
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        
        if(x > sum) {
            return -1;
        }
        
        int res = INT_MAX;
        sum = 0;
        
        unordered_map<int, int> mp;
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(sum == x) {
                res = min(res, i + 1);
            }
        }
        
        sum = 0;
        
        for(int i = n - 1; i >= 0; i--) {
            sum += nums[i];
            mp[sum] = n - i;
        }
        
        if(mp.find(x) != mp.end()) {
            res = min(res, mp[x]);
        }
        
        sum = 0;
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            
            if(mp.find(x - sum) != mp.end()) {
                res = min(res, i + 1 + mp[x - sum]);
            }
        }
        
        if(res == INT_MAX) {
            return -1;
        }
        
        return res;
    }
};