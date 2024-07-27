//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    string removeDups(string str) {
        // Your code goes here
        int i=0;
        string temp ="";
        vector<int>freq(26,0);
        while(i<str.length()){
            
            
            if(freq[str[i]-'a'] ==0){
                temp+=str[i];
                freq[str[i]-'a']=1;
            }
            
            i++;
        }
        return temp;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends
