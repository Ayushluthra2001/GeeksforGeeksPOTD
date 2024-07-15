//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    string solve(int s, int d,string temp, string& ans,vector<vector<string>>&dp){
        if(s<0 || d<0) return "0" ;
        if(s==0 && d==0){
            if(ans.length()==0) ans = temp;
            else{
                int curr = stoi(temp);
                int curr2 = stoi(ans);
                if(curr2>curr) ans = temp;
                
            }
           return temp; 
        }
        if(dp[s][d]!="-1") return dp[s][d];
        if(temp.length()==0){
            for(int i=1;i<=9;i++){
            string curr = temp;
            curr+=to_string(i);
            
            solve(s-i,d-1,curr,ans,dp);
            
        }
        }else{
            for(int i=0;i<=9;i++){
            string curr = temp;
            curr+=to_string(i);
            
            solve(s-i,d-1,curr,ans,dp);
            
        }
        }
        
        return dp[s][d] = temp;
    }
    string smallestNumber(int s, int d) {
        // code here
        string ans="";
         vector<vector<string>>dp(s+1,vector<string>(d+1,"-1"));
         solve(s,d,"",ans,dp);
         
         if(ans.length()==0) return "-1";
         return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends
