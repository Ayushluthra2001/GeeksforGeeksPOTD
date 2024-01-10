//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    unordered_map<int,int>mapping;
	    int sum=0;
	    mapping[0]=-1;
	    int ans=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	        int rem=sum%k;
	        
	        if(rem<0){
	            rem+=k;
	        }
	        if(mapping.find(rem)==mapping.end()){
	            mapping[rem]=i;
	        }else{
	            int index=mapping[rem];
	            int len=i-index;
	            ans=max(ans,len);
	        }
	    }
	    return ans;
	    
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends
