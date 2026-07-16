class Solution {
public:
 int drow[4]={-1,0,+1,0};
 int dcol[4]={0,+1,0,-1};
void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis){
    vis[i][j]=1;
    int m=grid.size();
    int n=grid[0].size();
    queue<pair<int,int>> q;
    q.push({i,j});
    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int newr=drow[i]+row;
            int newc=dcol[i]+col;
            if(newr>=0 && newr<m && newc>=0 && newc<n && vis[newr][newc]==0 && grid[newr][newc]=='1'){
                q.push({newr,newc});
                vis[newr][newc]=1;
            }
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    bfs(i,j,grid,vis);
                    islands++;
                }
                else{
                    vis[i][j]=1;
                }
            }
        }
        return islands;
    }
};