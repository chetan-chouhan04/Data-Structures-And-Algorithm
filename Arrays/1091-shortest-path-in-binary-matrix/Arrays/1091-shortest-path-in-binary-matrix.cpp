class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        if(grid[0][0]==0 && grid[n-1][n-1]==0)
        q.push({1,{0,0}});
        else
        return -1;
        dist[0][0]=1;
        int drow[]={-1,-1,-1,0,+1,+1,+1,0};
        int dcol[]={-1,0,+1,+1,+1,0,-1,-1};
        while(!q.empty()){
            int dis=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            for(int i=0;i<8;i++){
                int newr=drow[i]+row;
                int newc=dcol[i]+col;
                if(newr>=0 && newr<n &&
                    newc>=0 && newc<n &&
                    dis+1<dist[newr][newc] && 
                    grid[newr][newc]==0){
                        dist[newr][newc]=dis+1;
                        q.push({dis+1,{newr,newc}});
                    }

            }
        }
        if(dist[n-1][n-1]==1e9)
        return -1;
        return dist[n-1][n-1];
    }
};