//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        // code here
       int start=0;
       int end=0;
       int mini=INT_MAX;
       int lastX=-1,lastY=-1;
       for(int i=0;i<n;i++){
           if(a[i]==x ){
               lastX=i;
              if(lastY!=-1) mini=min(abs(lastX-lastY),mini);
               
           }else if(a[i]==y){
               lastY=i;
              if(lastX!=-1) mini=min(abs(lastX-lastY),mini);
           }
       }
       
       return mini==INT_MAX ? -1 : mini;
       
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends
