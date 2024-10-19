//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        // Complete the function
          int n = str.size();
        
        int last_digit = str[n - 1] - '0';
        
        if(last_digit > 5){
            
            
            str[n - 1] = '0';
            
           
            int carry = 1;
            
            int i = n - 2;
            while(i >= 0 && carry){
                
                int cur_digit = (str[i] - '0') + carry;
                carry = cur_digit / 10;
                
                if(cur_digit > 9){
                    str[i] = '0';
                }
                else {
                    str[i] = cur_digit + '0';
                    return str;
                }
                
                i--;
                
            }
            
            if(carry){
                return "1" + str;
            }
            
        }
        
        str[n - 1] = '0';
        return str;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends
