//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
       int dp[101][101][101];
    long long solve(int n ,int k , vector<vector<int>>&arr, int i , int j){
        if(i>=n || j>=n || k<0 ) return 0;
        if(i==n-1 && j==n-1){
            //cout<<"H"<<endl;
            //cout<<count<<endl;
            
            if(k==arr[i][j]) return 1;
           
            return 0;
            
            
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
           // visted[i][j]=1;
        int includeDown=solve(n,k-arr[i][j],arr,i+1,j);
        int includeRight=solve(n,k-arr[i][j],arr,i,j+1);
        //visted[i][j]=0;
      
        
        return dp[i][j][k]=includeDown+includeRight;
        
    }
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        

        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                for(int l=0;l<=k;l++){
                    dp[i][j][l]=-1;
                }
            }
        }
        long long ans=solve(n,k,arr,0,0);
        return ans;
        // Code Here
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends
