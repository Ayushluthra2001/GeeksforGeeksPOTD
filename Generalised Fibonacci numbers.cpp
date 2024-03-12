//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  
public:
  vector<vector<long long>> multiply(vector<vector<long long>> mat1, vector<vector<long long>> mat2, long long m){
      vector<vector<long long>>ans(3, vector<long long>(3,0));
      for(int i=0;i<3;i++){
          for(int j=0;j<3;j++){
              for(int k=0;k<3;k++){
                  ans[i][j]=(ans[i][j]+mat1[i][k]*mat2[k][j])%m;
              }
          }
      }
      return ans;
  }
  vector<vector<long long>> matrixMult(vector<vector<long long>> mat, long long n, long long m){
      if(n==1){
          return mat;
      }
      vector<vector<long long>> prod=matrixMult(mat,n/2,m);
      prod=multiply(prod,prod,m);
      if(n%2)prod=multiply(prod,mat,m);
      return prod;
  }
    long long genFibNum(long long a, long long b, long long c, long long n, long long m) {
        // code here
        if(n<=2){
            return 1;
        }
        vector<vector<long long>>v(3, vector<long long>(3,0));
        v[0][0]=a, v[0][1]=b, v[0][2]=1,v[1][0]=1, v[2][2]=1;
        v=matrixMult(v,n-2,m);
        return (v[0][0]+v[0][1]+c*v[0][2])%m;
    }

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a,b,c,n,m;
        
        cin>>a>>b>>c>>n>>m;

        Solution ob;
        cout << ob.genFibNum(a,b,c,n,m) << endl;
    }
    return 0;
}
// } Driver Code Ends
