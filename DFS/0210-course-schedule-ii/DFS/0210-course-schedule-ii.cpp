class Solution {
public:
bool dfs(int node, vector<int>& vis, stack<int>& st, vector<vector<int>> &adj, vector<int> &path){
    vis[node]=1;
    path[node]=1;
    for(auto it : adj[node]){
        if(!vis[it]){
            if(dfs(it,vis,st,adj,path)==false)
            return false;
        }
        else if(path[it]==1){
            return false;
        }
    }
    st.push(node);
    path[node]=0;
    return true;
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int source = prerequisites[i][1];
            int target = prerequisites[i][0];
            adj[source].push_back(target);
        }
        vector<int> vis(numCourses, 0);
        vector<int> path(numCourses, 0);
        stack<int> st;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,vis,st,adj,path)==false)
                return {};
            }
        }
        vector<int> ans;
      
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
        
        }
        
        return ans;
    }
};