//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string A, string B)
	{
	    int carry=0;
	    string ans="";
	   
	   
	    int index1=A.length()-1;
	    int index2=B.length()-1;
	    
	    while(index1>=0 && index2>=0){
	        if( A[index1]=='1' && B[index2]=='1'){
	            if(carry==1){
	                ans+="1";
	                carry=1;
	            }else{
	                ans+="0";
	                carry=1;
	            }
	       }else if(A[index1]=='1' && B[index2]=='0'){
	           if(carry==1){
	               ans+="0";
	               carry=1;
	           }else{
	               ans+="1";
	               carry=0;
	           }
	       }else if(A[index1]=='0' && B[index2]=='1'){
	           if(carry==1){
	               ans+="0";
	               carry=1;
	           }else{
	               ans+="1";
	               carry=0;
	           }
	       }else{
	           if(carry==1){
	               ans+="1";
	               carry=0;
	           }else{
	               ans+="0";
	               carry=0;
	           }
	       }
	       index1--;
	       index2--;
	    }
	    if(index1>=0){
	        while(index1>=0){
	            if(carry==1 && A[index1]=='1'){
	                ans+="0";
	                carry=1;
	            }else if(carry==0 && A[index1]=='1'){
	                ans+="1";
	                carry=0;
	            }
	            else if(carry==1 && A[index1]=='0'){
	                ans+="1";
	                carry=0;
	            }else{
	                ans+="0";
	                carry=0;
	            }
	            index1--;
	        }
	        
	    }
	    if(index2>=0){
	        while(index2>=0){
	            if(carry==1 && B[index2]=='1'){
	                ans+="0";
	                carry=1;
	            }else if(carry==0 && B[index2]=='1'){
	                ans+="1";
	                carry=0;
	            }
	            else if(carry==1 && B[index2]=='0'){
	                ans+="1";
	                carry=0;
	            }else{
	                ans+="0";
	                carry=0;
	            }
	             index2--;
	        }
	       
	    }
	    if(carry==1){
	        ans+="1";
	    }
	    
	   
	    reverse(ans.begin(),ans.end());
	   
	     int i=0;
	    while(i<ans.length() && ans[i]=='0'){
	        i++;
	    }
	    return ans.substr(i);
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
