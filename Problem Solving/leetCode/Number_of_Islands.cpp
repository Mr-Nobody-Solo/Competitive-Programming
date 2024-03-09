class Solution {
public:

    int m,n;
    const int fx[8]={-1,1,0,0,  1,1,-1,-1};
    const int fy[8]={0,0,1,-1,  -1,1,-1,1};

    void dfs(int x,int y,vector<vector<char>>& adj){
    if(x<0 || x>=m || y<0 || y>=n)return;
    if(adj[x][y]!='1')return;
    adj[x][y]='2';
    for(int i{0};i<4;i++){
        int new_x=x+fx[i];
        int new_y=y+fy[i];
        dfs(new_x,new_y,adj);
    }
    }
int numIslands(vector<vector<char>>& grid) {
    m = grid.size();
    n = grid[0].size();
    int cnt{0};
    for(int i{0};i<m;i++){
        for(int j{0};j<n;j++){
        if(grid[i][j]=='1'){
            cnt++;
            dfs(i,j,grid);
        }
        }
    }
    return cnt;
} 
};