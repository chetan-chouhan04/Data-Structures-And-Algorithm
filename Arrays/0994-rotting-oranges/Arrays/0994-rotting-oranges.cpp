class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid[0].size();
        int m=grid.size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2 ){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        int time=0;
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            time=max(time,t);
            q.pop();
            for(int i=0;i<4;i++){
                int newr=row+drow[i];
                int newc=col+dcol[i];
                
                if(newr>=0 && newr<m && newc>=0 && newc < n && vis[newr][newc] == 0 && grid[newr][newc] == 1){
                    vis[newr][newc]=1;
                    q.push({{newr,newc},t+1});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    return -1;
                }
            }
        }
        return time;
    }
};