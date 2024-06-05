//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        sort(a,a+n);
        sort(b,b+m);
        int totalA=accumulate(a,a+n,0);
        int totalB=accumulate(b,b+m,0);
        int i=0,j=0;
        while(i<n && j<m){
            int k=totalA-a[i]+b[j];
            int l=totalB+a[i]-b[j];
            if(k==l) return 1;
            if(k>l) i++;
            else j++;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
