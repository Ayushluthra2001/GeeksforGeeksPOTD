//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int LongestBitonicSequence(vector<int>nums) {
	    int n = nums.size();
	    int dp[n+1] = {0}, dp_rev[n+1] = {0};
	    vector <int> v;
	    v.push_back(nums[0]);
	    dp[0] = 1;
	    for(int i=1; i<n; i++){
	        auto it = lower_bound(v.begin(), v.end(), nums[i]);
	        if(it == v.end())
	            v.push_back(nums[i]);
	        else
	            *it = nums[i];
	        dp[i] = max((int)v.size(), dp[i-1]);
	    }
	    v.clear();
	    v.push_back(nums[n-1]);
	    dp_rev[n-1] = 1;
	    for(int i=n-2; i>=0; i--){
	        auto it = lower_bound(v.begin(), v.end(), nums[i]);
	        if(it == v.end())
	            v.push_back(nums[i]);
	        else
	            *it = nums[i];
	        dp_rev[i] = max((int)v.size(), dp_rev[i+1]);
	    }
	    int ans = 0;
	    for(int i=0; i<n; i++){
	        ans = max(ans, dp[i]+dp_rev[i]-1);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
