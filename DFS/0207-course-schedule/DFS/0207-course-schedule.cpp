class Solution {
public:
bool dfs(int i, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathvis){
    vis[i]=1;
    pathvis[i]=1;
    for(auto it : adj[i]){
        if(!vis[it]){
            if(dfs(it, adj,vis,pathvis)==true)
            return true;
        }
        else if(pathvis[it] == 1){
            return true;
        }
    }
    pathvis[i]=0;
    return false;

}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses, 0);
        vector<int> pathvis(numCourses, 0);
        for(auto it : prerequisites){
            int target = it[0];
            int source = it[1];
            adj[source].push_back(target);
        }
        //bool ans;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,  adj, vis, pathvis))
                return false;
            }
        }
        return true;
    }
};