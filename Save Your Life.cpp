//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          // code here 
          map<char,int>mapping;
          string temp="";
          for(int i=0;i<w.length();i++){
              mapping[w[i]]=w[i];
          }
          for(int i=0;i<n;i++){
              mapping[x[i]]=b[i];
          }
          string ans="";
          int maxi=INT_MIN; 
          int curr=0;
          for(int i=0;i<w.length();i++){
              
              curr+=mapping[w[i]];
              temp+=w[i];
              if(curr>maxi){
                  maxi=curr;
                  ans=temp;
              }
              if(curr<0){
                  curr=0;
                  temp="";
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
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends
