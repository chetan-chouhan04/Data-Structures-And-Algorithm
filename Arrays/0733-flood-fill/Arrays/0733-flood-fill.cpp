class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        if(image[sr][sc]==color)
        return image;
        vector<vector<int>> vis(m,vector<int>(n));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc]=1;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int drow[] = {-1,0,+1,0};
            int dcol[] = {0,+1,0,-1};
            for(int i=0;i<4;i++){
                int newr=drow[i]+row;
                int newc=dcol[i]+col;
                if(newr >= 0 && newr < m && newc >= 0 && newc < n && image[newr][newc]==image[sr][sc] && vis[newr][newc]==0){
                    image[newr][newc] = color;
                    vis[newr][newc] = 1;
                    q.push({newr,newc});
                }
            }
        }
        image[sr][sc]=color;
        return image; 
    }
};