//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	void solve(vector<string>&ans,int curr,string s,string temp){
	    if(curr>=s.length()) {
	        if(temp.length()>=1)
	        ans.push_back(temp);
	        return ;
	    }
	    solve(ans,curr+1,s,temp+s[curr]);
	    
	    solve(ans,curr+1,s,temp);
	}
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string>ans;
		    solve(ans,0,s,"");
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends
