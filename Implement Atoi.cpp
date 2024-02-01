//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        
        //Your code here
        int count =0;
        int index=-1;
        int count2=0;
        int index2=-1;
        for(int i=0;i<s.length();i++){
            
           if(s[i]=='-' && index==-1) count++,index=i;
            else if(s[i]>='0' && s[i]<='9') continue;
            else return -1;
        }
      
        if(count>1) return -1;
        if(count==1 && index!=0) return -1;
       int maxi=INT_MAX;
       int ans=0;
       long long temp=0;
       for(int i=0;i<s.length();i++){
           if(s[i]=='-' || s[i]=='+') continue;
           else {
               
               temp=temp*10+s[i]-'0';
               //if(temp>INT_MAX || temp<INT_MIN) return -1;
               //else
               ans=(int)temp;
           }
       }
       if(s[0]=='-') ans*=-1;
       return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends
