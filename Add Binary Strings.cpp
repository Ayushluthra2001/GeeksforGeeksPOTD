//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        string result ="";
        int i = s1.length()-1, j = s2.length()-1;
        int carry = 0;
        while( i >=0 && j>=0 ){
            int curr = carry + s1[i]-'0' + s2[j]-'0';
            
            if(curr==3) carry = 1, curr = 1;
            else if(curr==2) carry = 1, curr = 0;
            else if(curr == 1) carry = 0, curr = 1;
            else if(curr ==0 ) carry=0, curr = 0;
            result += curr +'0';
            i-- , j--;
        }
      
        while( i >=0 ){
            int curr = carry + s1[i]-'0';
            if(curr ==2) carry = 1, curr=0;
            else if(curr==1) carry=0, curr=1;
            else carry = 0, curr = 0;
            result+=curr+'0';
            i--;
            
        }
        
         while( j >=0  ){
            int curr = carry + s2[j]-'0';
            if(curr ==2) carry = 1, curr=0;
            else if(curr==1) carry =0,curr =1;
            else curr = 0, carry =0;
            result+=curr+'0';
            j--;
            
        }
        if(carry == 1){
            result+='1';
            carry = 0;
        }
      
        i = result.length()-1;
        while(i>=0 && result[i]=='0'){
           // cout<<result[i]<<" ";
            result.pop_back();
            i--;
        }
      
        reverse(result.begin(),result.end());
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
