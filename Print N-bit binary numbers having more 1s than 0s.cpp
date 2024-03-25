//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
void solve(int Countone,int Countzero,string temp,vector<string>&ans,int n){
    if(n==0){
        ans.push_back(temp);
        return;
    }
    solve(Countone+1,Countzero,temp+'1',ans,n-1);
    if(Countone>Countzero) solve(Countone,Countzero+1,temp+'0',ans,n-1);
}
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    vector<string>ans;
	    solve(0,0,"",ans,n);
	
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends
