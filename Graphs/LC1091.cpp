class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0] == 1) return -1;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        
        grid[0][0] = 1; 
        
        int dist = 1;
        
        vector<pair<int,int>> dir = {
            {-1,-1},{-1,0},{-1,1},
            {0,-1},        {0,1},
            {1,-1},{1,0},{1,1}
        };
        
        while(!q.empty()) {
            int size = q.size();
            
            while(size--) {
                auto [r,c] = q.front();
                q.pop();
                
                if(r == n-1 && c == n-1) return dist;
                
                for(auto [dr,dc] : dir) {
                    int nr = r + dr;
                    int nc = c + dc;
                    
                    if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==0) {
                        q.push({nr,nc});
                        grid[nr][nc] = 1; 
                    }
                }
            }
            dist++;
        }
        
        return -1;
    }
};
