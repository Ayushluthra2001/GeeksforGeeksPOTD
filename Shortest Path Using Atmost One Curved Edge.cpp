//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dis(V+5, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // store distance and node
        dis[S] = 0;
        pq.push({0, S});
        while(!pq.empty()) {
            int node = pq.top().second;
            int dis_curr = pq.top().first;
            pq.pop();
            for(auto& it: adj[node]) {
                int nxt_dis = dis_curr + it[1];
                if(dis[it[0]]>nxt_dis) {
                    dis[it[0]] = nxt_dis;
                    pq.push({nxt_dis, it[0]});
                }
            }
        }
        return dis;
    }
    int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges) {
        vector<vector<int>> adj[n+5];
        for(auto& x: edges) {
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }
        vector<int> disa = dijkstra(n, adj, a);
        vector<int> disb = dijkstra(n, adj, b);
        int ans = disa[b];
        for(auto x: edges) {
            if(disa[x[0]]!=INT_MAX && disb[x[1]]!=INT_MAX) {
                int now = disa[x[0]] + disb[x[1]] + x[3]; 
                ans = min(ans, now);
            }
            swap(x[0], x[1]);
            if(disa[x[0]]!=INT_MAX && disb[x[1]]!=INT_MAX) {
                int now = disa[x[0]] + disb[x[1]] + x[3]; 
                ans = min(ans, now);
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,a,b;
        cin>>n>>m;
        cin>>a>>b;
        
        vector<vector<int>> edges;
        
        for(int i=0; i<m; i++)
        {
            int u,v,x,y;
            cin>>u>>v>>x>>y;
            edges.push_back({u,v,x,y});
        }

        Solution ob;
        cout << ob.shortestPath(n,m,a,b,edges) << endl;
    }
    return 0;
}
// } Driver Code Ends
