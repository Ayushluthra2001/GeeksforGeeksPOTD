//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        // code here
        int i=0;
        int j=-1;
        while(i<N){
            if(S[i]=='1'){
                if(j>=i-X-1){
                    j  =i+X;
                    
                    
                }
                i++;
                
                
            }
            else{
                i++;
            }
        }
        if(j>=N-1){
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends
