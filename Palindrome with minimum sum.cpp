//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int minimumSum(string s) {
        // code here
        int l=0,h=s.length()-1,ans=0,t1,t2;
        
        while(l<=h) {
            
            if(s[l]!='?' and s[h]=='?') {
                s[h]=s[l];
            }
            else if(s[l]=='?' and s[h]!='?') {
                s[l]=s[h];
            }
            else if(s[l]=='?' and s[h]=='?') {
                if(l==0) {
                    int x=l,y=h;
                    while(x<=y) {
                        if(s[x]=='?' and s[y]=='?') {
                
                        }
                        else if((s[x]=='?' and s[y]!='?') or (s[y]=='?' and s[x]!='?') or (s[x]==s[y])) {
                            char c;
                            t1=x,t2=y;
                            if(s[x]!='?') c=s[x];
                            if(s[y]!='?') c=s[y];
                            while(x>=0 and y<s.length()) {
                                s[x]=c;
                                s[y]=c;
                                x--,y++;
                            }
                            l=t1,h=t2;
                            break;
                        }
                        else if(s[x]!=s[y]) {
                            return -1;
                        }
                        x++,y--;
                    }
                }
                else {
                    s[l]=s[l-1];
                    s[h]=s[l];
                }
            }
            else if(s[l]!=s[h]) {
                return -1;
            }
            l++,h--;
            
        }
        for(int i=0; i<s.length()-1; ++i) {
            if(s[i]!=s[i+1]) {
                ans+=(int)(abs(s[i+1]-s[i]));
            }
        }
        
        return ans;
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
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
