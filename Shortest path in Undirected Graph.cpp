//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        // code here
        unordered_map<int,vector<int>>adj;
        
        for(int i = 0;i<m;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>dist(n,1e9);
        
        queue<int>q;
        q.push(src);
        dist[src] = 0;
        while(!q.empty()){
            int  front = q.front();
            q.pop();
            for(auto it : adj[front]){
                if(dist[front] + 1 < dist[it]){
                    dist[it] = dist[front] + 1;
                    q.push(it);
                }
            }
            
        }
        vector<int>ans(n,-1);
        
        for(int i = 0; i<n; i++){
            if(dist[i] != 1e9){
                ans[i] = dist[i];
            }
        }
        
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
