//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
       int n=s.length();
        
        int f[26]={0};
        
        for(int i=0; i<n; i++){
            f[s[i]-'a']=i;
        }
        
        int cnt=1;
        int end=0;
        
        for(int i=0; i<n; i++){
            if(end<i) cnt++;
            end=max(end, f[s[i]-'a']);
        }
        
        return cnt;
        
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
