class Solution {
public:
    
    /*
        First approach - Sorting
        
        sort(nums.begin(), nums.end(), greater<int>());    
        
        return nums[k-1];
    */
    
    
    /*
        Second Approach - Max Heap
        
        priority_queue<int> pq;
        
        for(auto num : nums) {
            pq.push(num);
        }
        
        while(true) {
            if(k == 1) {
                break;
            }
            pq.pop();
            k--;
        }
        
        return pq.top();
    */
    
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int top;
        
        for(auto num : nums) {
            pq.push(num);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        return pq.top();
    }
};