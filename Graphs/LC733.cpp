class Solution {
    void dfs(vector<vector<int>>& image , int r,int c,int color,int newcolor){
        int n = image.size();
        int m = image[0].size();

        if(r<0 || c<0 || r>=n || c>=m || image[r][c]!= color) return;

        image[r][c] = newcolor;
        dfs(image,r+1,c,color,newcolor);
        dfs(image,r,c-1,color,newcolor);
        dfs(image,r-1,c,color,newcolor);
        dfs(image,r,c+1,color,newcolor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) {
        int color = image[sr][sc];
        if(color == newcolor) return image;
        dfs(image,sr,sc,color,newcolor);
        return image;
    }
};
