//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	# define mod 1000000007;
		int CountWays(string str){
		    // Code here
		   
		    if(str[0]=='0') return 0;
		    vector<int>dp(str.length(),0);
		    dp[0]=1;
		    for(int i=1;i<str.length();i++){
		        char ch=str[i-1];
		        char ch2=str[i];
		        string temp="";
		        temp+=ch;
		        temp+=ch2;
		        
		       
		        if(temp[0]=='0' && temp[1]!='0'){
		            dp[i]=dp[i-1]%mod;   
		        }else if(temp[0]!='0' && temp[1]=='0'){
		            
		            if((str[i-1]=='1' || str[i-1]=='2')){
		                dp[i]+=( i>=2 ? dp[i-2]:1)%mod;
		            }
		        }else if(temp[0]!='0' && temp[1]!='0'){
		            dp[i]=dp[i-1]%mod;
		            if(stoi(temp)<=26){
		                dp[i]+=(i>=2 ? dp[i-2]:1)%mod;
		            }
		            
		        }else{
		            dp[i]=0;
		        }
		    }
		    return dp[dp.size()-1]%mod;
		    
		}
		

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
