class Solution {
public:
void bfs(int root,vector<int>& vis,vector<vector<int>>& isConnected){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int i=0;i<isConnected.size();i++){
            if(node!=i && vis[i]==0 && isConnected[node][i]==1){
                q.push(i);
                vis[i]=1;
            }
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        int provinces=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(i,vis,isConnected);
                vis[i]=1;
                provinces++;
            }
        }
        return provinces;
    }
};