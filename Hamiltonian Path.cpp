//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
     bool flag = false;
    void solve(vector<int> adj[],int i,int N,vector<int>&vis)
    {
        //Base
        if(vis[i]) return;
        
        vis[i] = 1;
        
        int check = accumulate(vis.begin(),vis.end(),0);
        if(check==N+1) flag = true;
        
        for(auto x : adj[i])
        {
            solve(adj,x,N,vis);
        }
        
        vis[i] = 0;
        
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        // code here
        vector<int> adj[N+1];
        for(int i=0;i<M;i++)
        {
            adj[Edges[i][0]].push_back(Edges[i][1]);
            adj[Edges[i][1]].push_back(Edges[i][0]);
        }
        vector<int> vis(N+1,0);
        vis[0] = 1;
        for(int i=1;i<=N;i++)
        {
            if(!flag) solve(adj,i,N,vis);
            else return true;
        }
        return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends
