class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> distance(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0 && !vis[i][j]){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                   // distance[i][j]=0;
                }
            }
        }

        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,+1,0,-1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newr = drow[i]+row;
                int newc = dcol[i]+col;
                if(newr >= 0 && newr < m && newc >= 0 && newc < n && !vis[newr][newc] && mat[newr][newc] == 1){
                    vis[newr][newc]=1;
                    q.push({{newr, newc},dist+1});
                    distance[newr][newc] = dist+1;
                }
            }
            
        }
        return distance;
    }
};