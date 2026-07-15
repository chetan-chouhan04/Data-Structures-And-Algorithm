class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int,  int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || i==m-1 || j==0 || j==n-1) && board[i][j] == 'O'){
                    vis[i][j]=1;
                    q.push({i,j});
                    board[i][j]='#';
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
                   board[newr][newc]=='O'){
                    vis[newr][newc]=1;
                    q.push({newr,newc});
                    board[newr][newc]='#';
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O')
                board[i][j]='X';
                else if(board[i][j]=='#')
                board[i][j]='O';
            }
        }
    }
};