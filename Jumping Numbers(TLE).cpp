//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool check(long long  i ){
      
      vector<long long>ans;
      while(i>0){
          ans.push_back(i%10);
          i=i/10;
      }
      for(int i=0;i<ans.size()-1;i++){
          if(abs(ans[i]-ans[i+1])!=1) return false;
      }
      return true;
  }
    long long jumpingNums(long long X) {
        // code here 
        if(X<=10) return X; 
        long long maxi=10;
        for(long long  i=11;i<=X;i++){
            if(check(i)){
                maxi=max(i,maxi);
            }
        }
        return maxi;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends
