//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
        unordered_map<char,int>mapping,mapping2;
        int x=0;
        int y=0;
        for(int i=0;i<s.length();i++){
            
                mapping[s[i]]++;
           
            
        }
       for(auto i : mapping){
          
           int z=(i.first-'a')+1;
           if(z%2==0 && mapping[i.first]%2==0) y++;
           if(z%2!=0 && mapping[i.first]%2!=0)x++;
           
       }
        
        return (x+y)%2==0 ? "EVEN":"ODD";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends
