//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    bool composite[1000001];
    vector<int> primes;
    
    int findPar(int u, vector<int>& par){
        return (par[u]==u) ? u : par[u]=findPar(par[u], par);
    }
    
    void _union(int u, int v, vector<int>& par, vector<int>& _rank){
        u = findPar(u, par);
        v = findPar(v, par);
        if(u != v){
            if(_rank[u] < _rank[v]) swap(u, v);
            par[v] = u;
            _rank[u] += _rank[v];
        }
    }
public:
    void precompute(){
        for(int i=2; i<=1000; ++i){
            if(!composite[i]){
                for(int j=i; i*j<=1e6; ++j) composite[i*j] = true;
            }
        }
        
        for(int i=2; i<=1e6; ++i){
            if(!composite[i]) primes.push_back(i);
        }
    
    }
    int helpSanta(int n, int m, vector<vector<int>> &g){
        // Code here
        if(m == 0) return -1;
        vector<int> _rank(n+1, 1), par(n+1);
        iota(par.begin(), par.end(), 0);
        for(int i=1; i<=n; i++){
            for(int j: g[i]) _union(i, j, par, _rank);
        }
        int mx = 1;
        for(int i=1; i<=n; i++) mx = max(mx, _rank[i]);
        return primes[mx-1];
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends
