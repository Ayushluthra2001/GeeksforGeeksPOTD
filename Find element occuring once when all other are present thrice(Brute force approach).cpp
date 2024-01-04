//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        // code here
        // int temp=arr[0];
        // for(int i=1;i<N;i++){
        //     temp=temp^arr[i];
        // }
        // return temp;
        unordered_map<int,int>mapping;
        for(int i=0;i<N;i++){
            mapping[arr[i]]++;
        }
        for(auto i : mapping){
            if(i.second==1) return i.first;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
