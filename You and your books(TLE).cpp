//{ Driver Code Starts
#include <algorithm>
#include <cstdio>
#include <iostream>
//#include<Windows.h>
using namespace std;


// } Driver Code Ends


#include<bits/stdc++.h>
class Solution {
  public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k) {
        // Your code here
        long long  maxi=0;
       // unordered_map<long long ,long long>mapping;
        
        for(int i=0;i<n;i++){
            if(arr[i]<=k){
                long long count=0;
                for(int j=i;j<n;j++){
                    if(arr[j]<=k) count+=arr[j];
                    else break;
                }
              //  cout<<count<<endl;
                //mapping[count]++;
                maxi=max(maxi,count);

            }
            
        }
        // for(auto i : mapping){
        //     maxi+=i.first>=2 ? i.first:0;
        // }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ar[n];
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }
        Solution ob;
        cout << ob.max_Books(ar, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends
