//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{

public:
    int solve(int num, int n, int m){
        int ans=0;
        if(num>m) return 0;
        
        if(num>=n && num<=m) ans++;
        int last= num%10;
        if(last!=0){
            ans+= solve((num*10) + (last-1), n, m);
        }
        if(last!=9){
            ans+= solve((num*10)+ (last+1), n, m);
        }
        return ans;
    }

    int steppingNumbers(int n, int m){
        int ans=0;
        if(n==0) ans++;
        for(int i=1;i<=9;i++){
            ans+= solve(i, n, m);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends
