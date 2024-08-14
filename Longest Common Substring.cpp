//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    void solve(string &str1,string &str2,int i, int j,int curr,int &maxi){
            
        if(i>=str1.length() || j>=str2.length()) return ;
       
        if(str1[i] == str2[j]){
            curr= curr+1;
            maxi = max(maxi,curr);
            solve(str1,str2,i+1,j+1,curr,maxi);
             solve(str1,str2,i,j+1,0,maxi);
             solve(str1,str2,i+1,j,0,maxi);
            
        }else{
             solve(str1,str2,i,j+1,0,maxi);
             solve(str1,str2,i+1,j,0,maxi);
            
            
        }
        
        return ; 
    }
    int longestCommonSubstr(string str1, string str2) {
        // your code here
        // int maxi = 0;
         int curr = 0;
         int maxi = 0;
        
         solve(str1,str2,0,0,curr,maxi);
        return maxi; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends
