class Solution {
public:
    
    void traverse(int pos, int n, vector<bool>& visited, int& ways) {
        if(pos > n) {
            ways++;
            return;
        }
        
        for(int i = 1; i <= n; i++) {
            if(!visited[i] and (i % pos == 0 || pos % i == 0)) {
                visited[i] = true;
                traverse(pos+1, n, visited, ways);
                visited[i] = false;
            }
        }
    }
    
    int countArrangement(int n) {
        int ways = 0;
        vector<bool> visited(n+1, false);
        
        traverse(1, n, visited, ways);
        
        return ways;
    }
};