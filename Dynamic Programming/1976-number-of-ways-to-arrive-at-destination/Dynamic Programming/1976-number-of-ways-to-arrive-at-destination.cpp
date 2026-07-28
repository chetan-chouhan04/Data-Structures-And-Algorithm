class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;
        vector<long> dist(n, LLONG_MAX);
        dist[0]=0;
        pq.push({0, 0});
        ///int count=0;
        int mod = (int)(1e9+7);
        vector<int> ways(n,0);
        ways[0]=1;
        while(!pq.empty()){
            int node=pq.top().second;
            long long dis=pq.top().first;
            pq.pop();
            if(dis > dist[node]) continue;
            for(auto it : adj[node]){
                int neigh = it.first;
                int wt = it.second;
                if(dis+wt < dist[neigh]){
                    dist[neigh] = dis+wt;
                    pq.push({dis+wt, neigh});
                    ways[neigh]=ways[node];
                }
                else if(dis+wt == dist[neigh]){
                    ways[neigh] = (ways[node]+ways[neigh])%mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};