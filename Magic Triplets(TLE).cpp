//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>nums){
	    // Code here.
	    int count=0;
	    for(int i=0;i<nums.size();i++){
	        for(int j=i+1;j<nums.size();j++){
	            for(int k=j+1;k<nums.size();k++){
	                if(nums[i]<nums[j] && nums[j]<nums[k]) count++;
	            }
	        }
	    }
	    return count;
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
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends
