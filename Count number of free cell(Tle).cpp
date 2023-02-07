//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      //Code Here
      vector<long long int>ans;
      vector<vector<int>>matrix(n,vector<int>(n,0));
      for(int i=0;i<arr.size();i++){
          int r=arr[i][0]-1;
          int c=arr[i][1]-1;
          for(int k=0;k<n;k++){
              matrix[r][k]=1;
          }
          for(int k=0;k<n;k++){
              matrix[k][c]=1;
          }
          long long int count=0;
          for(int i=0;i<n;i++){
              for(int j=0;j<n;j++){
                   //cout<<matrix[i][j]<<" ";
                  if(matrix[i][j]==0) count++;
              }
               //cout<<endl;
          }
           //cout<<i<<endl;
          ans.push_back(count);
      }
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends
