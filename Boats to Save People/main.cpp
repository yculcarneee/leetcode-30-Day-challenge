class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int i = people.size() - 1, j = 0, res = 0;
        
        while(j <= i) {
            if(people[j] + people[i] <= limit) {
                j++;
            }
            i--;
            res++;
        }
        
        
        return res;
    }
};