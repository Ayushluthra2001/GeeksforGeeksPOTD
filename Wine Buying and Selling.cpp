//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& arr, int n){
     long long int b=0,s=0;
     long long int ans=0;   
     while(b<n && s<n){
         while(arr[b]<=0){
            b++;
            if(b==n) return ans;
         }
         while(arr[s]>=0){
             s++;
             if(s==n) return ans;
         }
         if(abs(arr[b])>=abs(arr[s])){
             ans+=abs(b-s)*abs(arr[s]);
         arr[b]+=arr[s];
         arr[s]=0;
         }else{
              ans+=abs(b-s)*abs(arr[b]);
               arr[s]+=arr[b];
         arr[b]=0;
         }
         
     }
     return ans;
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
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
