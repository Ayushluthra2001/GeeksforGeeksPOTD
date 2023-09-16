//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long solve(int n,int curr){
        if(curr==n) return 1;
        if(curr>n) return 0;
        int first =solve(n,curr+1);
        int second =solve(n,curr+2);
        int third =solve(n,curr+3);
        return (first+second+third)%1000000007;
    }
    long long countWays(int n)
    {
        
        // your code here
        return solve(n,0);
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends
