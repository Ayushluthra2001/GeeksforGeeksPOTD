//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        vector<int>max_arr(n,0);
        vector<int>min_arr(n,0);
        int maxi = INT_MIN;
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,a[i]);
            max_arr[i]=maxi;
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,a[i]);
            min_arr[i]=mini;
        }
        int ans =-1;
        int i=0,j=0;
        while(i<n && j<n){
            if(max_arr[j]>=min_arr[i]){
                ans=max(ans,j-i);
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends
