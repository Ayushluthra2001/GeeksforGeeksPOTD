//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int countOfSubstrings(string S, int k) {
        int count=0;
         map<char,int>mapping;
       for(int i=0;i<k;i++){
          mapping[S[i]]++;
          
           
       }
       
       int i=0;
       int j=k;
       while(j<=S.length()){
           if(mapping.size()==k-1) count++;
           if(j==S.length()) break;
           
           mapping[S[i]]--;
          
           if(mapping[S[i]]==0){
                mapping.erase(S[i]);
           }
           
          
           mapping[S[j]]++;
           i++;
           j++;
       }
       return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin>>S;
        cin>>K;

        Solution ob;
        cout << ob.countOfSubstrings(S,K) << endl;
    }
    return 0;
}
// } Driver Code Ends
