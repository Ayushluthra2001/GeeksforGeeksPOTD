//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	    string temp="";
	    unordered_map<char,int>mapping;
	    for(int i=0;i<str.length();i++){
	        if(mapping[str[i]]>=1){
	            continue;
	        }else{
	            temp+=str[i];
	            mapping[str[i]]++;
	        }
	    }
	    return temp;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
