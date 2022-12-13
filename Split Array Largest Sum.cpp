//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool ispos(int arr[],int n,int k,int mid){

      int cnt=1,temp=0;

            for(int i=0;i<n;i++){

                if(temp+arr[i]<=mid)temp+=arr[i];

                else{

                    cnt++;

                    temp=arr[i];

                }

            }

            

            if(cnt<=k)return true;

            return false;

  }

    int splitArray(int arr[] ,int n, int k) {

        // code here

        int sum=0,maxi=INT_MIN;

        for(int i=0;i<n;i++){

            sum+=arr[i];

            maxi=max(maxi,arr[i]);

        }

        int ans=INT_MIN;

        while(maxi<=sum){

            int mid=(maxi+sum)/2;

            if(ispos(arr,n,k,mid)){

                ans=mid;

                sum=mid-1;

            }

            else{

                maxi=mid+1;

            }

        }

        return ans;

    }


};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
