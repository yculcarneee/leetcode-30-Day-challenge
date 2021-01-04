class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        map<int, vector<int>> mp;
        
        for(auto piece : pieces) {
            mp[piece[0]] = piece;
        }
        
        int i = 0;
        
        while(i < arr.size()) {
            if(mp.find(arr[i]) == mp.end()) {
                return false;
            }
            else {
                int j = 0;
                vector<int>  temp = mp[arr[i]];
                while(j < temp.size()) {
                    if(arr[i] != temp[j]) {
                        return false;
                    }
                    j++;
                    i++;
                }
            }
        }
        
        return true;
    }
};