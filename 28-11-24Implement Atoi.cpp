//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
       
        long long digit = 0;
        int size = strlen(s);
        int i =0;
        int negative = 0;
        while(i < size && s[i] ==' ')i++;
        while(i < size && s[i] == '0' ) {
            i++;
        }
        if(s[i]=='-') negative = 1,i++;
        
        
        
        while(i < size){
           
            if(!isdigit(s[i]) ) break;
        
            int curr = s[i] - '0';
            digit = digit*10 + (long long)curr;
            if(digit > INT_MAX)  break; 
            i++;
            
            
        }
      
        if(negative==1) digit*=-1;
        if(digit < INT_MIN) return INT_MIN;
        if(digit > INT_MAX) return INT_MAX;
        
        return digit;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends
