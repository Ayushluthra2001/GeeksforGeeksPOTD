//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        // Complete the function
       map<int,int>mapping;
       for(int i=0;i<n;i++){
           mapping[a[i]]++;
       }
        int sum=0;
        for(int i=n-1;i>=0;i--){
            int key=a[i];
            if(mapping[key]>0){
              sum+=key;
              mapping[key]--;
              mapping[key-1]--;
            }
        }
        return sum;
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends
