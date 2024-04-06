//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
	int solve(int n, int m, int a[],int b[]){
	    if(n<0 || m<0 ) return 0;
	    int include=a[n]*b[m]+solve(n-1,m-1,a,b);
	    int exclude=(n==m) ? 0 : solve(n-1,m,a,b);
	    return max(include,exclude);
	}
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
		// Your code goes here
		return solve(n-1,m-1,a,b);
		
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
