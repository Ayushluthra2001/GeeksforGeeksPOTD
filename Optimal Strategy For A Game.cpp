//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long maximumAmount(int n, int arr[]){
        // Your code here
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            dp[i][i]=arr[i];
        }
        for(int i=0;i<n-1;i++){
            dp[i][i+1]=max(arr[i], arr[i+1]);
        }
        for(int g=2;g<n;g++){
            for(int i=0;i+g<n;i++){
                int j=g+i;
                dp[i][j]=max(arr[i]+min(dp[i+2][j], dp[i+1][j-1]), arr[j]+min(dp[i+1][j-1], dp[i][j-2]));
            }
        }
        return dp[0][n-1];
    }
};



//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends
