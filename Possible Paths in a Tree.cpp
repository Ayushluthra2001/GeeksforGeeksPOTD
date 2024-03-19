//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    
    int Find(int u, vector<int> &parent){
        if(parent[u] == u) return u;
        return parent[u] = Find(parent[u], parent);
    }
    int Union(int pu, int pv, vector<int> &parent, vector<int> &size){
        int ans = size[pu] * size[pv];
        //cout << size[pu] << " " << size[pv] << endl;
        if(size[pu] >= size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
            } else { 
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        return ans;
    }
public:
vector<int> maximumWeight(int n, vector<vector<int>> edges, int q, vector<int> &queries)
{
    // code here
    int m = edges.size();
    
    unordered_map<int, vector<pair<int, int>>> mp;
    
    int maxi = INT_MIN;
    for(int i = 0; i < m; i++){
        mp[edges[i][2]].push_back({edges[i][0], edges[i][1]});
        maxi = max(maxi, edges[i][2]);
    }
    
 
    
    vector<int> parent(n + 1, 0), size(n + 1, 1);
    
    for(int i = 0; i <= n; i++) {
        parent[i] = i;
    }
    
    vector<int> temp(maxi + 1, 0);
    
    for(int i = 0; i <= maxi; i++){
        if(i != 0) temp[i] += temp[i - 1];
        if(mp.count(i) != 0){
            for(auto it : mp[i]){
                int pu = Find(it.first, parent);
                int pv = Find(it.second, parent);
                if(pu != pv) {
                    temp[i] += Union(pu, pv, parent, size);
 
                }
            }
        }
        //cout << temp[i] << endl;
    }
    vector<int> ans(q, 0);
    
    for(int i = 0; i < q; i++){
        if(queries[i] <=  maxi) ans[i] = temp[queries[i]]; 
        else ans[i] = temp[maxi];
    }
    
    return ans;
    
}
};



//{ Driver Code Starts.

int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
        cin >> n;
        
        vector<vector<int>> edges(n-1, vector<int> (3, 0));

        for(int i = 0; i < n-1; i++)
        {
        	for(int j = 0; j < 3; j++)
        	{
        		cin >> edges[i][j];
        	}
        }

        int q;
        cin >> q;
        vector<int> queries(q);
        for(int i = 0; i < q; i++)
        	cin >> queries[i];

    	Solution obj;
    	vector<int> ans = obj.maximumWeight(n, edges, q, queries);

    	for(auto i:ans)
    		cout << i << " ";
    	cout << "\n"; 
    }
    return 0;
}

// } Driver Code Ends
