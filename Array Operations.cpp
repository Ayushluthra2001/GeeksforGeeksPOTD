//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        // code here
        int i=0;
        int count=0;
        int zero=0;
        while(i<n){
            int j=i;
            while(j<n && arr[j]!=0) j++;
            if(j>=0 && arr[j-1]!=0) count++;
            
            
            if(j==n){
                if(zero==0) return -1;
                else return count;
            }
            if(arr[j]==0) zero++;
            
            i=j+1;
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
