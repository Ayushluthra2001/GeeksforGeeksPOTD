//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    int solve(vector<int>&prices,int curr,int canBuy,int left,vector<vector<vector<int>>>&dp){
        if( curr==prices.size()) return 0;
        if(left==0) return 0;
        if(dp[curr][canBuy][left]!=-1) return dp[curr][canBuy][left];
        int profit=0;
        
        if(canBuy){
            int choice1=-prices[curr]+solve(prices,curr+1,0,left,dp);
            int choice2=solve(prices,curr+1,1,left,dp);
            profit=max(choice1,choice2);
        }else{
            int choice1=prices[curr]+solve(prices,curr+1,1,left-1,dp);
            int choice2=solve(prices,curr+1,0,left,dp);
            profit=max(choice1,choice2);
                
        }
        return dp[curr][canBuy][left] =profit;
    }
    public:
        //User function Template for C++
        
        int maxProfit(vector<int>&prices){
            //Write your code here..
             vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
            
           return solve(prices,0,1,2,dp);
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends
