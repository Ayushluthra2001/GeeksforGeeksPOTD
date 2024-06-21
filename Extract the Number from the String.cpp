//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  long long reverse(long long ans){
      if(ans==0) return 0;
      
      long long temp=0;
      while(ans>0){
          temp=temp*10 + (ans%10);
          ans=ans/10;
      }
      return temp;
  }
    long long ExtractNumber(string sentence) {

        // code here
        long long ans=0;
        long long maxi=-1;
        int i=0;
        while(i<sentence.length()){
            int j=i;
            if(isdigit(sentence[j])){
                ans=0;
                bool flag=false;
                while(j<sentence.length() && isdigit(sentence[j])){
                    if(sentence[j]=='9') {
                        flag=true;
                        
                    }
                   ans= ans*10+(sentence[j]-'0');
                    j++;
                }
               // cout<<ans<<endl;
                   // ans=reverse(ans);
                 if(!flag)
                 maxi=max(maxi,ans);
            }
            i=j+1;
           
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends
