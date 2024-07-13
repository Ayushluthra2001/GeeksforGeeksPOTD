//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        vector<int>ans;
         queue<int>pq;
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=INT_MAX;
        }
        dp[1][0]=0;
        
        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        pq.push(1);
        while(!pq.empty())
        {
            int x=pq.front();
            for(auto itr:adj[x])
            {
                if(dp[x][0]+itr.second<dp[itr.first][0])
                {
                    dp[itr.first][0]=dp[x][0]+itr.second;
                    dp[itr.first][1]=x;
                    pq.push(itr.first);
                }
            }
            pq.pop();
        }
        if(dp[n][1]==-1)
        {
            return {-1};
        }
        ans.push_back(dp[n][0]);
        int i=n;
        while(i>=1)
        {
            ans.push_back(i);
            i=dp[i][1];
        }
        reverse(ans.begin()+1,ans.end());
      
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends
