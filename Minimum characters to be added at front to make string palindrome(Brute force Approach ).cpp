//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool checkPlaindrome(string s){
        int st=0,e=s.length()-1;
        while(st<=e){
            if(s[st]!=s[e]) return false;
            st++;
            e--;
        }
        return true;
    }
public:
    int minChar(string str){
       int count=0;
       int s=0,e=str.length()-1;
       for(int i=e;i>=0;i--){
           if(checkPlaindrome(str.substr(0,i+1))) return count;
           count++;
           
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
