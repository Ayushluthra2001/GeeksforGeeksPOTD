//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    string printString(string s, char ch, int count) {
        // Your code goes here
        if(count==0) return s.substr(1,s.length());
        int currCount =0;
        for(int i=0;i<s.length();i++){
            if(ch==s[i]){
                if(currCount<count)
                currCount++;
               
                   // cout<<"H"<<endl;
                if(currCount==count)
                return s.substr(i+1,s.length());
                
            }
        }
       // cout<<currCount<<endl;
    
        if(currCount<count) return "";
        return s;
        
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
        char ch;
        int count;

        cin >> s >> ch >> count;
        Solution ob;
        cout << ob.printString(s, ch, count) << "\n";
    }

    return 0;
}
// } Driver Code Ends
