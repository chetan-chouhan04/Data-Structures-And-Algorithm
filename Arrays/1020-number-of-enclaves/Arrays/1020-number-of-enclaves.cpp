class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int,  int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || i==m-1 || j==0 || j==n-1) && grid[i][j] == 1){
                    vis[i][j]=1;
                    q.push({i,j});
                    grid[i][j]=-1;
                }
            }
        }
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newr=drow[i]+row;
                int newc=dcol[i]+col;
                if(newr>=0 && newr<m && 
                   newc>=0 && newc<n && 
                   vis[newr][newc]==0  && 
                   grid[newr][newc]==1){
                    vis[newr][newc]=1;
                    q.push({newr,newc});
                    grid[newr][newc]=-1;
                }
            }
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                count++;
                //else if(grid[i][j]=='#')
                //grid[i][j]=1;
            }
        }
        return count;
    }
};