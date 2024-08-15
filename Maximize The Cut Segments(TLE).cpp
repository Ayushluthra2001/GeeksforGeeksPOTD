//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int solve(int n , int x , int y , int z){
        if(n<0) return INT_MIN;
        if(n==0) return 0;
        
        int cut1 = 1 + solve(n-x,x,y,z);
        int cut2 = 1 + solve(n-y,x,y,z);
        int cut3 = 1 + solve(n-z,x,y,z);
        
        return max(cut1 , max(cut2,cut3));
        
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        int ans = solve(n,x,y,z) ;
         return ans<0 ? 0 :ans  ;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends
