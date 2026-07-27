class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : flights){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
            //adj[v].push_back({u,wt});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> dist(n, 1e9);
        pq.push({0,src,0});
        //stop, node, distance
        dist[src]=0;
        while(!pq.empty()){
            int stop = pq.top()[0];
            int node = pq.top()[1];
            int dis = pq.top()[2];
            pq.pop();
            if(stop+1 <= k+1){
                for(auto it : adj[node]){
                    int wt=it.second;
                    int neigh = it.first;
                    if(dis+wt < dist[neigh]){
                        dist[neigh] = dis + wt;
                        pq.push({stop+1, neigh, dist[neigh]});
                    }
                }
            }
        }
        if(dist[dst]==1e9)
        return -1;
        return dist[dst];
    }
};