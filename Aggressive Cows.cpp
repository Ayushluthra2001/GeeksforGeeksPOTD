//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class Solution {
public:

    bool possible(int n, int k, vector<int> &a,int mid)
    {
        int i,st=0;
        k--;
        
        for(i=1;i<n;i++)
        {
            if(a[i]-a[st]<mid)
            continue;
            
            k--;
            st=i;
            
            if(k==0)
            return 1;
        }
        
        return k==0;
    }

    int solve(int n, int k, vector<int> &a) {
    
        // Write your code here
        sort(a.begin(),a.end());
        
        int l=0,h=a[n-1]-a[0];
        int ans=0;
        
        while(l<=h)
        {
            int mid=(l+h)/2;
            
            if(possible(n,k,a,mid))
            {
                ans=mid;
                l=mid+1;
            }
            else
            h=mid-1;
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
