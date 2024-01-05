//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here  2 3 5
	    if(N==1 )return 4 ;
	    if(N==2) return 9;
	    long  first=2;
	    long  second =3;
	    long third;
	    for(int i=3;i<=N;i++){
	        third=(first%1000000007+second%1000000007)%1000000007;
	        first=second%1000000007;
	        second=third%1000000007;
	    }
	    return (third%1000000007*third%1000000007)%1000000007;
	 
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
