class Solution {
public:
    
    /*  First Approach - 
    
        vector<int> tempVector;
        
        for(int i = 0; i < m; i++) {
            tempVector.push_back(nums1[i]);
        }
        
        for(auto num : nums2) {
            tempVector.push_back(num);
        }
        
        sort(tempVector.begin(), tempVector.end());
        
        for(int i = 0; i < m+n; i++) {
            
            nums1[i] = tempVector[i];
        }
    */
    
    /*  Second Approach - 
    
        int findFirstElemLarger(vector<int>& nums1, int num, int m) {
        for(int i = 0; i < m; i++) {
            if(nums1[i] > num) {
                return i;
            }
        }
        
        return m;
    }
    
    void insertElem(vector<int>& nums1, int num, int m, int idx) {
        for(int i = m; i > idx; i--) {
            nums1[i] = nums1[i-1];
        }
        nums1[idx] = num;
    }
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = 0; i < n; i++) {
            int idx = findFirstElemLarger(nums1, nums2[i], m);
            insertElem(nums1, nums2[i], m, idx);
            m++;
        }   
    } */

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        
        while (last >= 0) {
            while(i >= 0 && j >= 0) {
                if(nums1[i] > nums2[j]) nums1[last--] = nums1[i--];
                else nums1[last--] = nums2[j--];
            }
            while (i >= 0) {
                nums1[last--] = nums1[i--];
            }
            while(j >= 0) {
                nums1[last--] = nums2[j--];
            }
        }
    }

};