//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int m)
		{
		    // Code here
		    if (n == 0) return 1;
            long long int result = 1;
            while (n > 0) {
                if (n % 2 == 1) {
                    result = (result * x) % m;
                }
            x = (x * x) % m;
            n /= 2;
        }
            return result;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends
