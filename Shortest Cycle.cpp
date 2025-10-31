class Solution {
  public:
    int shortCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        int m = edges.size(), ans = V + 1;
        
        vector<vector<int>> adj(V);
        
        for(int i = 0; i < m; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        for(int i = 0; i < V; i++) {
            
            vector<int> vis(V, -1);
            queue<pair<int, int>> q;
            
            q.push({i, -1});
            vis[i] = 0;
            
            while(!q.empty()) {
                
                int node = q.front().first, parent = q.front().second;
                q.pop();
                
                for(auto nbr : adj[node]) {
                    if(vis[nbr] == -1) {
                        q.push({nbr, node});
                        vis[nbr] = vis[node] + 1;
                    } else if(nbr != parent) {
                        ans = min(ans, vis[nbr] + vis[node] + 1);
                    }
                }
                
            }
            
            // cout << ans << endl;
        }
        
        if(ans > V) ans = -1;
        
        return ans;
    }
};
