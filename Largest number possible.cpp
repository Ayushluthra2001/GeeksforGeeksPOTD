//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int s){
        // code here
        if(N==1 && s>9) return "-1";
        if(N>1 && s==0) return "-1";
        string ans="";
      
        for(int i=0;i<N;i++){
            if(s>=9){
                ans+="9";
                s-=9;
            }else{
                ans+=to_string(s);
                s-=s;
                break;
            }
        }
        for(int i=ans.length();i<N;i++){
            ans+='0';
        }
        if(s>0) return "-1";
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
