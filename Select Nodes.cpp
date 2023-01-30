//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int fn(int curr,int par,int state,vector<int> adj[],vector<vector<int>>& memo)
  {
      if(memo[curr][state]!=-1) return(memo[curr][state]);
      int res,res1=INT_MAX,res2=INT_MAX;
      res1=1;
      for(auto x : adj[curr])
      {
          if(x==par) continue;
          res1=res1+fn(x,curr,1,adj,memo);
      }
      if(state==1)
      {
          res2=0;
          for(auto x : adj[curr])
          {
              if(x==par) continue;
              res2=res2+fn(x,curr,0,adj,memo);
          }
      }
      res=min(res1,res2);
      return(memo[curr][state]=res);
  }
    int countVertex(int n, vector<vector<int>>edges)
    {
        vector<vector<int>> memo(n+1,vector<int>(2,-1));
        vector<int> adj[n+1];
        for(auto x : edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        return(fn(1,-1,1,adj,memo));
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
