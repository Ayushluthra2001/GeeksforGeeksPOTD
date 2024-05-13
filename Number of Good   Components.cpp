//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<bool> &visited, unordered_set<int> &st){
        visited[node] = true;
        st.insert(node);
        for(int &neigh : adj[node]){
            if(visited[neigh] == false){
                dfs(neigh, adj, visited, st);
            }
        }
    }
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        vector<int> adj[v+1];
        for(int i = 0; i < e; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count = 0;
        vector<bool> visited(v+1, false);
        for(int i = 1; i <= v; ++i){
            if(visited[i] == false){
                unordered_set<int> st;
                dfs(i, adj, visited, st);
                bool flag = true;
                for(int node : st){
                    if(adj[node].size() != (st.size()-1)){
                        flag = false;
                        break;
                    }
                }
                if(flag)    count++;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends
