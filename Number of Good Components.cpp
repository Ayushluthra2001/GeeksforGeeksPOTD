//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<bool>visited;
    bool dfs(int node,vector<vector<int>>&adj,int &number_of_nodes)
    {
        visited[node]=true;
        bool ans=true;
        number_of_nodes++;
        for(int i=0;i<adj[node].size();i++)
        {
            int child=adj[node][i];
            if(!visited[child])
            {
                ans=ans&dfs(child,adj,number_of_nodes);
            }
        }
        if(adj[node].size()!=number_of_nodes-1)
        {
            return false;
        }
        return ans;
    }
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        // code here

        visited=vector<bool>(V+1,false);
        int good=0;
        for(int i=1;i<=V;i++)
        {
            int number_of_nodes=0;
            if(visited[i]==false)
            {
                bool is_good=dfs(i,adj,number_of_nodes);
                if(is_good==true)
                {
                    good++;
                }
            }
        }
        return good;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends
