//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string s, string w){
        // code here 
        int count=0;
        vector<bool>vis(s.length(),false);
        for(int i=0;i<s.length();i++){
            if(s[i]==w[0] && !vis[i]){
                int k=1;
                vis[i]=true;
                bool find=false;
                for(int j=i+1;j<s.length();j++){
                    if(k==w.length()){
                        count++;
                        find=true;
                        break;
                    }
                    if(s[j]==w[k] && !vis[j]){
                        vis[j]=true;
                        k++;
                    }
                }
                if(k==w.length() && !find) count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends
