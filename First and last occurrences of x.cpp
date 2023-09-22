//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int solve1(int arr[],int start,int end,int x){
        int  occ=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]>x){
                end=mid-1;
            }else if(arr[mid]==x){
              occ=mid;
              end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return occ;
    }
     int solve2(int arr[],int start,int end,int x){
        int  occ=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]>x){
                end=mid-1;
            }else if(arr[mid]==x){
              occ=mid;
              start=mid+1;
            }else{
                start=mid+1;
            }
        }
        return occ;
    }
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int first=solve1(arr,0,n-1,x);
        int last=solve2(arr,0,n-1,x);
        return {first,last};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends
