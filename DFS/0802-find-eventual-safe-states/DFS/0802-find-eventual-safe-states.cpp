class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> adjrev(n);
        vector<int> inorder(n);
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adjrev[it].push_back(i);
                inorder[i]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(inorder[i]==0)
            q.push(i);
        }

        vector<int> safenodes;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safenodes.push_back(node);
            for(auto it:adjrev[node]){
                inorder[it]--;
                if(inorder[it]==0)
                q.push(it);
            }
        }
        sort(safenodes.begin(),safenodes.end());
        return safenodes;
    }
};