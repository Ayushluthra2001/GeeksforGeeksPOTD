//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


#define ll long long 
class Solution{



    int mod = 1e9 + 7;

     ll power(ll x, ll y,int p) {

//Modular exponentiation

      ll res = 1;   

      x = x % p; 

      if (x == 0) return 0; 

      while (y > 0) {    

        if (y & 1) res = (res*x) % p;     

        y = y>>1; 

        x = (x*x) % p;

      }

      return res;

    }

    long long inv(int A){

         return power(A,mod-2,mod); //TC: O(logm)

        //Fermats little theorem if m is odd

        

    }

 public:

 int compute_value(int n){

     long long int ans =1, ncr=1;

     for(int i=1;i<=n;i++){

         ncr=(((ncr*(n+1-i))%mod)*inv(i))%mod;

         ans=(ans+(ncr*ncr)%mod)%mod;

     }

     return ans%mod;

 }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
