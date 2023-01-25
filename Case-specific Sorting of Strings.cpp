//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
       
        int k=0,l=0;
        vector<char>lower;
        vector<char>upper;
        for(int i=0;i<n;i++){
            if(str[i]>='A' && str[i]<='Z') upper.push_back(str[i]);
            else lower.push_back(str[i]);
        }
        sort(lower.begin(),lower.end());
        sort(upper.begin(),upper.end());
        for(int i=0;i<n;i++){
            if(str[i]>='A' && str[i]<='Z') str[i]=upper[k++];
            else str[i]=lower[l++];
        }
        return str;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends
