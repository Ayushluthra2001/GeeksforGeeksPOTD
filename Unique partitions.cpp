//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	void solve(int i,int n,int sum,vector<int>&v,vector<int>temp,vector<vector<int>>&ans){
	    if(sum>n)return;
	    if(i>=n){
	        if(sum==n)ans.push_back(temp);
	        return;
	    }
	   
	    temp.push_back(v[i]);
	    solve(i,n,sum+v[i],v,temp,ans);
	    temp.pop_back();
	    solve(i+1,n,sum,v,temp,ans);
	}
    vector<vector<int>> UniquePartitions(int n) {
      vector<int>v;
      for(int i=n;i>=1;i--)v.push_back(i);
      vector<vector<int>>ans;
      vector<int>temp;
      solve(0,n,0,v,temp,ans);
      return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends
