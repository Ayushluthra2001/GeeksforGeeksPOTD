//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
void solve(vector<vector<int>>& ans, vector<int> temp,vector<int>& arr, int n , int k , 
    int index , int currSum){
        if(currSum>k) return ;
        
        
        if(index>=n || currSum==k){
            if(currSum == k ) {
                // mapping[currMapIndex++]=temp;
                ans.push_back(temp);
                
            } return ;
            
        }
        solve(ans,temp,arr,n,k,index+1,currSum);
        temp.push_back(arr[index]);
        solve(ans,temp,arr,n,k,index+1,currSum+arr[index]);
        
        return ;
        
}
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        vector<vector<int>>ans;
        int currMapIndex=0;
       
        vector<int>temp;
        
        solve(ans,temp,arr,n,k,0,0);
        
       
        sort(ans.begin(),ans.end());
        
        
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
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
