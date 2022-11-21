//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>nums){
	  
	   // count = 18
	   //3 4 7 7 11 3 9 6 8
	                    
	    int count=0;
	    for(int i=0;i<nums.size();i++){
	        int countleft=0;
	        int countright=0;
	        for(int j=0;j<i;j++){
	            if(nums[j]<nums[i]) countleft++;
	        }
	        for(int j=i+1;j<nums.size();j++){
	            if(nums[j]>nums[i]) countright++;
	        }
	        if(countleft>0 && countright>0) count+=countleft*countright;
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
