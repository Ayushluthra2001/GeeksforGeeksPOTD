//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	// Complete the function
    	long long first=arr[0],second=INT_MAX;
    	long long first_max=arr[0],second_max=INT_MIN,third=INT_MIN;
    	
    // 		cout<<first_max<<" "<<second_max<<" "<<third<<endl;
    	for(int i=1;i<n;i++){
    	   if(first_max<=arr[i]){
    	       third=second_max;
    	       second_max=first_max;
    	       first_max=arr[i];
    	       
    	   }else if(second_max<=arr[i]){
    	       third=second_max;
    	       second_max=arr[i];
    	   }else if(third<=arr[i]){
    	       third=arr[i];
    	   }
    	}
    	
    	for(int i=1;i<n;i++){
    	    if(arr[i]<=first){
    	        second=first;
    	        first=arr[i];
    	    }else if(arr[i]<=second){
    	        second=arr[i];
    	    }
    	}
    // 	cout<<first_max<<" "<<second_max<<" "<<third<<endl;
    // 	cout<<first_max*first*second<<" "<<first_max*second_max*third<<endl;
    	return max(first_max*first*second,first_max*second_max*third);
    }
    
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends
