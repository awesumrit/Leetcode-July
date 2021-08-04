class Solution {
public:
    
    int dir[4][4] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    unordered_map<int, int> compSize;
    int m, n;
        
    void dfs(int x, int y, vector<vector<int>>& grid, int color){
        if(x<0 || y<0 || x==m || y==n || grid[x][y] != 1) return;
        compSize[color] += 1;
        grid[x][y] = color;
        for(int i=0; i<4; i++){
            dfs(x+dir[i][0], y+dir[i][1], grid, color);
        }  
    }
    int largestIsland(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        int color = 2, ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0) continue;
                dfs(i,j,grid,color++);
                // ans = max(ans, compSize[color - 1]);
            }
        }
        // cout<<color<<endl;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                // cout<<"grid"<<grid[i][j]<<endl;
                if(grid[i][j] != 0) continue;
                unordered_set<int> neigh;
                for(int r=0; r<4; r++){
                    int x = i+dir[r][0], y = j+dir[r][1];
                    // cout<<"x y"<<x<<" "<<y<<endl;
                    if(x<0 || y<0 || x==m || y==n || grid[x][y] == 0) continue;
                    // cout<<grid[x][y]<<' '<<compSize[grid[x][y]]<<endl;
                    neigh.insert(grid[x][y]);
                }
                int size = 1;
                for(int neigh_color : neigh){
                    // cout<<size<<endl;
                    size += compSize[neigh_color];
                    // cout<<size<<endl;
                }     
                ans = max(ans, size);
            }           
        }
        
        if(ans > 0)
            return ans;
        else{
            return m*n;
        }
    }
};


