//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	     int solve(int n , string str , unordered_map<string,int>&mapping){
	         if(n==0) {
	             sort(str.begin(),str.end());
	             mapping[str]++ ;
	             return 1;
	         }
	         if(n<0) return 0;
	         
	         int one = solve(n-1 , str+'1' , mapping);
	         int two = solve(n-2 , str +'2', mapping);
	         return one + two;
	     }
		int nthStair(int n){
		    //  Code here
		    string str = "";
		    unordered_map<string,int>mapping;
		     solve(n, str , mapping);
		  //  for(auto i : mapping) cout<<i.first<<" ";
		  //  cout<<endl;
		  return  mapping.size();
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
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
