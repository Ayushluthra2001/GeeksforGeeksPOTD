//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minCost(vector<vector<int>> &cost) {
       
       
       int k= cost[0].size();
       int N= cost.size();
        
       vector<vector<int>> dp(N, vector<int> (k,0));
        
       for(int i=0;i<k;i++)
         dp[0][i]=cost[0][i];
       
         

       for(int i=1;i<N;i++){
           
           int first_min = *min_element( dp[i-1].begin() ,  dp[i-1].end() );
           int index = min_element( dp[i-1].begin() ,  dp[i-1].end() ) - dp[i-1].begin();
           int sec_min = 1e9;
           
           for(int j=0;j<k;j++){
                        
                        if(j!=index)
                         sec_min = min( sec_min , dp[i-1][j] );
               
           }

           
           for(int j=0 ; j<k ; j++){
               
                if( first_min == dp[i-1][j])
                dp[i][j] = sec_min +  cost[i][j];
                
                else
                dp[i][j] = first_min + cost[i][j];
               
           }
       }
   

       int res = 1e8;
       for(int i=0; i<k;i++)
       res= min(res, dp[N-1][i]);
       
       if(res==1e8)
       return -1; 
       
       return res;
       

    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends
