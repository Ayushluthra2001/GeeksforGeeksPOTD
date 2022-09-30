
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  int solve(int n , int k){
      if(n==1) return 1;
      int ans=(solve(n - 1, k) + k-1) % n + 1;
      return ans;
  }
  
    int safePos(int n, int k) {
        // code here
        return solve(n,k);
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}
