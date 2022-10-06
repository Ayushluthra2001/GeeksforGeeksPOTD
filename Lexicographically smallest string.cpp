//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int power(int x){
      int count=0;
      while(x>0){
          if(x%2==1) count++;
          x=x/2;
      }
      if(count==1) return 1;
      return 0;
  }
    string lexicographicallySmallest(string S, int k) {
     
        int length=S.length();
        if(power(length)){
            k=k/2;
        }else{
            k=k*2;
        }
        
        int remove=0;
        if(k>=length) return "-1";
        stack<char>s;
        
        for(int i=0;i<length;i++){
            while(!s.empty() && remove<k && s.top()>S[i]) {
                    s.pop();
                    remove++;
            }
            s.push(S[i]);
        }
        while(remove<k){
            s.pop();
            remove++;
        }
        string ans="";
       
        while(s.size()>0){
            ans+=s.top();
            s.pop();
        }
         reverse(ans.begin(),ans.end()); 
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int k;
        cin >> S >> k;
        Solution ob;
        cout << ob.lexicographicallySmallest(S, k) << endl;
    }
    return 0;
}

// } Driver Code Ends
