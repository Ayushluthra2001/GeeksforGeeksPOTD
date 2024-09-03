//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int solve(string str1 , string str2 ,  int i , int j){
	    if(i == str1.length() || j==str2.length()) return 0;
	    
	    if(str1[i] == str2[j] ) {
	        return 1  + solve(str1,str2,i+1,j+1);
	    }else{
	        
	        
	        return  max(solve(str1,str2,i+1,j) , solve(str1,str2,i,j+1));
	    }
	    
	    return 0;
	    
	    
	    
	    
	    
	}
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    
	    int ls  = solve(str1,str2,0 ,0);
	    int needed = str2.length();
	    int extraNeeded = needed - ls ;
	    int curr = str1.length() - ls + extraNeeded;
	    
	    return  curr;
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
