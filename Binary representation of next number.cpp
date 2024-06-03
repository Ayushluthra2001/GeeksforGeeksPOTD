//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        string ans="";
        int carry=1;
        int i=s.length()-1;
        
        while(i>=0 || carry>0){
            if(i>=0 && s[i]=='1' && carry==1){
                carry=1;
                ans+='0';
            }else if(i>=0 && s[i]=='0' && carry==1){
                ans+='1';
                carry=0;
                
            }else if(i>=0 && s[i]=='1' && carry==0){
                ans+='1';
                
            }else if(carry==1) {
                ans+='1';
                carry=0;
            }else {
                ans+='0';
            }
            i--;
        }
        
        reverse(ans.begin(),ans.end());
        string temp="";
        i=0;
        while(i<ans.length() && ans[i]=='0') i++;
        while(i<ans.length()){
            temp+=ans[i];i++;
        }
        return temp;
    }
    
     
      
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends
