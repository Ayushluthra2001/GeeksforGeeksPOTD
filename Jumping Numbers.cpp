//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  void bfs(long long  X,long long i , long long &maxi ){
      queue<long long >q;
      q.push(i);
      while(!q.empty()){
          long long front=q.front();
          q.pop();
          if(front<=X){
              maxi=max(maxi,front);
          
          int last=front%10;
          if(last!=9){
              q.push((front*10)+(last+1));
          }
          if(last!=0){
              q.push((front*10) +(last-1));
          }
          }
      }
      
  }
    long long jumpingNums(long long X) {
        // code here 
        long long maxi=INT_MIN;
        for(long long i=1;i<=X && i<=9 ;i++){
            bfs(X,i,maxi);
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
