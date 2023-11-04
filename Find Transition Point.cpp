//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:    
    void solve(int &firstOcc,int arr[],int n){
        int start=0;
        int end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]==1){
                firstOcc=mid;
                end=mid-1;
            }else if(arr[mid]==0){
                start=mid+1;
            }
        }
    }
    int transitionPoint(int arr[], int n) {
        int firstOcc=-1;
        solve(firstOcc,arr,n);
        return firstOcc;
        // code here
    }
};

//{ Driver Code Starts.
int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.transitionPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
