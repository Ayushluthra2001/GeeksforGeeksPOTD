//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {

        

        int mx=0,ans=0,n= s.size();

        if(n<=2) return n;

        for(int i=2;i<n;i++)

        {

            int tind=0,cnt=0,ii=i;

            while(s[tind] == s[ii] && tind<i && ii<n)

                {

                    cnt++;

                    ii++;

                    tind++;

                }

            mx= max(mx, cnt );

        }

        if(mx==0) return n;

        return n-mx+1;

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends
