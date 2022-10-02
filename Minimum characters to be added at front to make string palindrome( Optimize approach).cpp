//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int minChar(string str){
       int s=0,e=str.length()-1;
       int count=0;
       int j2=e;
       while(s<=e){
           if(str[s]==str[e]){
               s++;
               e--;
               
           }else{
               count++;
               s=0;
               j2--;
               e=j2;
           }
       }
       return count;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends
