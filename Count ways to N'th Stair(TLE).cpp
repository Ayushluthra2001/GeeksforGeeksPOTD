//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long solve(int n,unordered_map<string,int>&mapping,string temp){
        sort(temp.begin(),temp.end());
        if(n==0 && mapping.find(temp)==mapping.end()){
            mapping[temp]++;
            return 1;
        }
        if(n<0) return 0;
        
        return solve(n-1,mapping,temp+'1')+solve(n-2,mapping,temp+'2');
        
    }
    long long countWays(int n) {
        // your code here
        unordered_map<string ,int>mapping;
        return solve(n,mapping,"");
    }
};

//{ Driver Code Starts.
int main() {
    // taking count of testcases
    int t;
    cin >> t;

    while (t--) {
        // taking stair count
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countWays(n) << endl; // Print the output from our pre computed array
    }
    return 0;
}
// } Driver Code Ends
