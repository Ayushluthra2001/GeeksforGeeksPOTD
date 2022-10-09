//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	bool isPrime(int n){
	    if(n==0 || n==1) return false;
	    for(int i=2;i<=sqrt(n);i++){
	        if(n%i==0) return false;
	    }
	    return true;
	}
		int NthTerm(int N){
		    if(isPrime(N)) return 0;
		    
		    int gap=1;
		    while(true){
		        if(isPrime(N+gap) || isPrime(N-gap)){
		            break;
		        }
		        gap++;
		    }
		    return gap;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		int ans = obj.NthTerm(N);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
