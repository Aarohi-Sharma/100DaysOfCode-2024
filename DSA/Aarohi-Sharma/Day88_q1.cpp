class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int currColor,int color,int i,int j){
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j]!=currColor or vis[i][j]){
            return;
        }
        vis[i][j]=1;
        vector<int> dir={-1,0,1,0,-1}; 
        for(int k=0;k<4;k++){
            int x=i+dir[k];
            int y=j+dir[k+1];
            if(x<0 or x>=grid.size() or y<0 or y>=grid[0].size() or (grid[x][y]!=currColor and !vis[x][y])){
                grid[i][j]=color;
            }
            dfs(grid,vis,currColor,color,x,y);
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        if(grid[row][col]==color) return grid; 
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,(vector<int>(n,0)));
        dfs(grid,vis,grid[row][col],color,row,col);
        return grid;
    }
};
