//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  int solve(int start, int end , string str){
      if(start>end) return 0;
      
      if(str[start]==str[end]){
          return solve(start+1,end-1,str);
      }else{
          int first = 1 + solve(start+1,end,str);
          int second = 1 + solve (start,end-1,str);
          return min(first,second);
      }
      return 0;
  }
    int countMin(string str){
    //complete the function here
    
         return solve(0,str.length()-1,str);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends
