//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
	int maxRemove = 0;
    bool dfs(int curr, int prev, vector<vector<int>>& adjacency) {
        bool odd = true;
        for(auto e : adjacency[curr]) {
            if(e == prev) continue;
            bool res = dfs(e, curr, adjacency);
            odd ^= res;
            maxRemove += (!res);
        }
        return odd;
    }
public:
    int minimumEdgeRemove(int n, vector<vector<int>>edges){
        vector<vector<int>> adjacency(n);
        for(auto e : edges) {
            adjacency[e[0]-1].push_back(e[1]-1);
            adjacency[e[1]-1].push_back(e[0]-1);
        }
        dfs(0, -1, adjacency);
        return maxRemove;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>edges;
		for(int i = 0; i < n-1; i++){
			int x, y;
			cin >> x >> y;
			edges.push_back({x,y});
		}
		Solution obj;
		int ans = obj.minimumEdgeRemove(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}

// } Driver Code Ends
