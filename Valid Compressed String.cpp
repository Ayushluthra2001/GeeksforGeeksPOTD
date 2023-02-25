//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        int s_len = S.length();
        int t_len = T.length();
        int s_index = 0;
        int t_index = 0;
        
        while(s_index < s_len && t_index < t_len) {
            if(S[s_index] == T[t_index]) {
                s_index++;
                t_index++;
                continue;
            }
            
            else if (!isalpha(T[t_index])) {
                int num = 0;
                while(t_index < t_len && !isalpha(T[t_index])) {
                    // stoi() was throwing error for huge number
                    num = num*10 + (T[t_index] - '0');
                    t_index++;
                }
                s_index += num;
            }
            
            else return 0;
        }
        if(s_index != s_len || t_index != t_len) return 0;
            
        return 1;
    }
};





//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends
