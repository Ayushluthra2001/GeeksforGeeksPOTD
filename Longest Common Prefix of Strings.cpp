//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        
        string res = "";
        int j=0;

        
        for(int i=0;i<arr[0].length();i++){
           char temp = arr[0][i];
          
           for(int j=1;j<arr.size();j++){
               if(temp!=arr[j][i]){
                   if(res.length()==0) return "-1";
                   else return res;
               }
           }
           res+=arr[0][i];
           
       }
       
       if(res.length()==0) return "-1";
       return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends
