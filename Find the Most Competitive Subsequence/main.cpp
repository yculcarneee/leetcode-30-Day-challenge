class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res;
        
        for(int i = 0; i < nums.size(); i++) {
            
            while(!res.empty() and res.back() > nums[i] and res.size() + (nums.size() - i - 1) >= k) {
                res.pop_back();
            }
            
            if(res.size() < k) {
                res.push_back(nums[i]);
            }
            
        }
        
        return res;
    }
};