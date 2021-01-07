class Solution {
public:
    
    /*
        Approach 1
    
        set<int> st(arr.begin(), arr.end());
        
        int i = 1, numMissing = 0;
        
        while(true) {
            if(st.find(i) == st.end()) {
                numMissing++;
            }
            
            if(numMissing == k) {
                return i;
            }
            
            i++;
        }       
        
        return 0;
    */
    
    int findKthPositive(vector<int>& arr, int k) {
        int start = 0, end = arr.size() - 1;
        
        while(start <= end) {
            int mid = start + (end - start) / 2;
            
            if(arr[mid] - (mid + 1) < k) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        
        return start + k;
        
    }
};