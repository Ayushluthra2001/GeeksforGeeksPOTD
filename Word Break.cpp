//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    int wordBreak(int n, string s, vector<string> &dictionary) {
       
      unordered_set<string>hash(dictionary.begin(),dictionary.end()) ;
      vector<int>dp(s.size()+1,0);
      
      dp[s.size()]=1 ;  
      
      for (int indx = s.size()-1 ; indx>=0 ; indx--) {
        string curr = "";

        for (int i =indx ; i<s.size() ;i ++) {
            
            curr+=s[i];

            bool flag1 = false ;
            
            if (hash.find(curr)!=hash.end()) {
                flag1 = true ;
            }
            else {
                continue ;
            }

            bool flag2 = dp[i+1];
            
            if (flag1 && flag2) {
                dp[indx] = true ;
                break ;
            }
        }
      }
      return dp[0];
    }
}; 


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends
