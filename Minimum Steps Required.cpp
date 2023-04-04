//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    int cnt1=0,cnt2=0;
    if(str[0]=='a') cnt1++;
    else cnt2++;
    for(int i=1;i<str.size();i++){
        if(str[i]!=str[i-1]){
            if(str[i]=='a') cnt1++;
            else cnt2++;
        }
    }
    if(cnt1==cnt2) return cnt1+1;
    return max(cnt1,cnt2);
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends
