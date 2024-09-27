class Solution {
public:
    bool isConnected(vector<vector<bool>>& vis, int& i, int& j){
        if(i==0)
            return true;
        if(i>0 && vis[i-1][j])
            return true;
        if(j>0 && vis[i][j-1])
            return true;
        if(i<vis.size()-1 && vis[i+1][j])
            return true;
        if(j<vis[0].size()-1 && vis[i][j+1])
            return true;
        return false;
    }
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        vector<int> ans(hits.size(), 0);
        vector<vector<int>> mat = grid;
        for(int i=0; i<hits.size(); i++)
            mat[hits[i][0]][hits[i][1]] = 0;
        vector<vector<bool>> vis(grid.size(), vector<bool> (grid[0].size(), false));
        queue<pair<int, int>> q;
        for(int i=0; i<grid[0].size(); i++){
            if(mat[0][i]==1){
                vis[0][i] = true;
                q.push({0, i});
            }
        }
        while(!q.empty()){
            int idx = q.front().first, jdx = q.front().second;
            q.pop();
            
            if(idx>0 && mat[idx-1][jdx]==1){
                if(!vis[idx-1][jdx])
                    q.push({idx-1, jdx});
                vis[idx-1][jdx]=true;
            }
            if(jdx>0 && mat[idx][jdx-1]==1){
                if(!vis[idx][jdx-1])
                    q.push({idx, jdx-1});
                vis[idx][jdx-1]=true;
            }
            if(idx<grid.size()-1 && mat[idx+1][jdx]==1){
                if(!vis[idx+1][jdx])
                    q.push({idx+1, jdx});
                vis[idx+1][jdx]=true;
            }
            if(jdx<grid[0].size()-1 && mat[idx][jdx+1]==1){
                if(!vis[idx][jdx+1])
                    q.push({idx, jdx+1});
                vis[idx][jdx+1]=true;
            }
        }
        for(int i=hits.size()-1; i>=0; i--){
            if(grid[hits[i][0]][hits[i][1]]==0)
                continue;
            mat[hits[i][0]][hits[i][1]] = 1;
            if(!isConnected(vis, hits[i][0], hits[i][1]))
                continue;
            q.push({hits[i][0], hits[i][1]});
            vis[hits[i][0]][hits[i][1]] = true;
            int cnt=0;
            while(!q.empty()){
                int idx = q.front().first, jdx = q.front().second;
                q.pop();
                cnt++;
                if(idx>0 && mat[idx-1][jdx]==1 && !vis[idx-1][jdx]){
                    q.push({idx-1, jdx});
                    vis[idx-1][jdx]=true;
                }
                if(jdx>0 && mat[idx][jdx-1]==1 && !vis[idx][jdx-1]){
                    q.push({idx, jdx-1});
                    vis[idx][jdx-1]=true;
                }
                if(idx<grid.size()-1 && mat[idx+1][jdx]==1 && !vis[idx+1][jdx]){
                    q.push({idx+1, jdx});
                    vis[idx+1][jdx]=true;
                }
                if(jdx<grid[0].size()-1 && mat[idx][jdx+1]==1 && !vis[idx][jdx+1]){
                    q.push({idx, jdx+1});
                    vis[idx][jdx+1]=true;
                }
            }
            ans[i] = cnt-1;
        }
        return ans;
    }
};
