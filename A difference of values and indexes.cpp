//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 



// } Driver Code Ends
class Solution{
  public:
    int maxDistance(int arr[], int n) 
    { 
        int a = INT_MIN, b = INT_MAX, c = INT_MIN, d = INT_MAX;

        for(int i=0; i<n; i++)

        {

            a = max(a, arr[i]-i);

            b = min(b, arr[i]-i);

 

            c = max(c, arr[i]+i);

            d = min(d, arr[i]+i);

        }

        return max(a-b, c-d);

    }
    
};

//{ Driver Code Starts.
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    Solution obj;
	    cout<<obj.maxDistance(arr, n)<<endl;
	}
} 

// } Driver Code Ends
