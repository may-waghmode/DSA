class Solution {
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& visited,int row,int col){
        visited[row][col]=1;
        int n = grid.size();
        int m=grid[0].size();
        int drow[] = {0,-1,0,1};
        int dcol[] = {-1,0,1,0};
        for(int i = 0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]=='1' && !visited[nrow][ncol]){
                dfs(grid,visited,nrow,ncol);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m= grid[0].size();
        int count = 0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    dfs(grid,visited,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
