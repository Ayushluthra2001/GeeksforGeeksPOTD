//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int i=0,j=0;
        int maxi=0;
        unordered_map<char,int>mapping;
        while(i<s.length() && j<s.length()){
            
            if(k>=mapping.size()){
                    while(j<s.length() && k>=mapping.size()){
                    mapping[s[j]]++;
                    if(mapping.size()==k){
                        maxi=max(maxi,j-i+1);
                        // cout<<maxi<<" "<<i<<" "<<j<<" "<<endl;
                    }
                    
                    
                    
                    j++;
                    
                }
                // cout<<"length of j "<<j<<endl;
                if(j==s.length()) return maxi ==0 ? -1 : maxi;
                
                
            }else{
                while(i<=j && mapping.size()>k){
                    mapping[s[i]]-=1;
                    if(mapping[s[i]]==0){
                        mapping.erase(s[i]);
                        // cout<<mapping.size()<<endl;
                        // for(auto i : mapping){
                        //     cout<<i.first<<" ";
                        // }
                        // cout<<endl;
                        // return 0;
                    }
                    i++;
                    
                    
                }
                // cout<<"i is"<<i<<endl;
                
                
                
                
            }
            // i=i+1;
            
            
        }
        return maxi==0 ? -1 :maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends
