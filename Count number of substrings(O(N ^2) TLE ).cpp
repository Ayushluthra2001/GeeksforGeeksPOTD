//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int substrCount (string s, int k) {
    	//code here.
    	//vector<string>substring;
    	long long int count=0;
    	for(int i=0;i<s.length();i++){
    	     map<char,int>mapping;
    	    for(int j=i;j<s.length();j++){
    	        mapping[s[j]]++;
    	        if( mapping.size()==k) count++;
    	        
    	        //cout<<mapping.size()<<endl;

    	    }
    	}
    	return count;
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends
