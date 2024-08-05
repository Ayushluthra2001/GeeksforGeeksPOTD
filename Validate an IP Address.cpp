//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
  public:
    int isValid(string str) {
        // code here
        int range = 255;
        int currTotal = 0;
        int i=0;
        int count = 0;
        while(i<str.length()){
            int j =i;
            string  temp = "";
            while(j<str.length() && str[j]!='.') temp+=str[j++];
            count++;
            if(temp.length()>3) return false;
            
            int check = stoi(temp);
            if(check>255) return false;
            i = j+1;
        }
       
        if(count==4) return true;
        
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends
