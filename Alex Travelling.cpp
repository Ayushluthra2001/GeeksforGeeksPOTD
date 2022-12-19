typedef long long ll;
class Solution {
  public:
    int minimumCost(vector<vector<int>>& fl, int n, int k) {
        vector<pair<ll,ll>> adj[n+1];
        ll u,v,wt;
        for(auto it : fl) {
            u = it[0], v = it[1], wt = it[2];
            adj[u].push_back({v,wt});   // because it is directed graph
        }
        
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        vector<ll> dist(n+1, LLONG_MAX);
        
        pq.push({0, k}); dist[k] = 0;
        
        while(!pq.empty()) {
            ll d = pq.top().first;
            ll curr = pq.top().second;
            pq.pop();
            
            for(auto it : adj[curr]) {
                ll next_node = it.first;
                ll next_dist = it.second;
                
                if(dist[next_node] > dist[curr] + next_dist) {
                    dist[next_node] = dist[curr] + next_dist;
                    pq.push({dist[next_node], next_node});
                }
            }
        }

        ll maxi = *max_element(dist.begin()+1, dist.end());
        
        return maxi == LLONG_MAX ? -1 : maxi;
    }
};
