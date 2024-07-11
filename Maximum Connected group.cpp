//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     class DSU {
        public:
        vector<int> par, sz;
        
        DSU(int n) {
            par.resize(n, 0), sz.resize(n, 1);
            for(int i=0; i<=n; i++) par[i]=i;
        }
        
        int findPar(int node) {
            if(node==par[node]) return node;
            
            return par[node] = findPar(par[node]);
        }
        
        void un(int u, int v) {
            int uup = findPar(u), vup = findPar(v);
            
            if(uup==vup) return;
            
            if(sz[uup]>=sz[vup]) {
                sz[uup]+=sz[vup];
                par[vup]=uup;
            } else {
                sz[vup]+=sz[uup];
                par[uup]=vup;
            }
        }
    };
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        
        DSU* dsu = new DSU(n*n);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==1) {
                    int ind = n*i + j;
                    if(j+1<n && grid[i][j+1]==1) dsu->un(ind, ind+1);
                    if(j-1>=0 && grid[i][j-1]) dsu->un(ind, ind-1);
                    if(i+1<n && grid[i+1][j]) dsu->un(ind, ind+n);
                    if(i-1>=0 && grid[i-1][j]) dsu->un(ind, ind-n);
                }
            }
        }
        
        int ans = 0;
        
        for(int i=0; i<n*n; i++) ans=max(ans, dsu->sz[i]);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(!grid[i][j]) {
                    int ind = n*i + j;
                    int temp = 1;
                    
                    unordered_set<int> st;
                    
                    if(j+1<n && grid[i][j+1]==1) st.insert(dsu->findPar(ind+1));
                    if(j-1>=0 && grid[i][j-1]) st.insert(dsu->findPar(ind-1));
                    if(i+1<n && grid[i+1][j]) st.insert(dsu->findPar(ind+n));
                    if(i-1>=0 && grid[i-1][j]) st.insert(dsu->findPar(ind-n));
                    
                    for(auto &i: st) temp+=dsu->sz[i];
                    
                    ans=max(ans, temp);
                }
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
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends
