//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        //10 2 2 1
        //2 10 1 2
        sort(arr.begin() , arr.begin() + (n/2));
        sort(arr.begin() + (n/2) , arr.end());
        int ans = 0;
        int right = n/2;
        for(int left = 0; left < n/2; left++){
            while(right < n and (arr[left] >= 5*arr[right])){
                right++;
            }
            ans += right - (n/2);
        }
        return ans;
    }  
};
// 6
// 0 4 3 -7 3 -8
// 4 3 3  0 -7 -8

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
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends
