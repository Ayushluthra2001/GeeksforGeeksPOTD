//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
      
        unordered_map<char,int>mapping;
        string temp ="";
        for(int i=0;i<str.length();i++){
            if(str[i]!=' '){
            mapping[str[i]]++;
             temp+=str[i];
            }
        
        }
        int rem = 26-mapping.size();
       if(temp.length()<26 || rem > k ) return false;
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends
