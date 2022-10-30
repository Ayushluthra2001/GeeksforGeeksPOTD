//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int NoOfChicks(int n){
	    vector<long long int>ans(n+1,0);
	    long long int sum=1;
	    int index=1;
	    ans[1]=1;
	    for(int i=2;i<=n;i++){
	        if(i>6){
	            sum-=ans[index++];
	        }
	        ans[i]=2*sum;
	        sum+=ans[i];
	    }
	    return sum;
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
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
