//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
#define mod 1000000007;
    int solve(int n, char ch, unordered_map<char,vector<char>>mapping ){
        if(n==0 && ch!='o') return INT_MIN;
        if(n==0 && ch=='o' ) return 1;
        int ans=0;
        for(auto i : mapping[ch]){
            // cout<<i<<endl;
            int curr=solve(n-1,i,mapping)%mod;
            // cout<<curr<<endl;
            if(curr>0) ans+=curr%mod;
        }
        return ans;
    }
    int countPaths(int N){
    
        if(N<2) return 0;
        unordered_map<char,vector<char>>mapping;
        mapping['o'].push_back('a');
        mapping['o'].push_back('b');
        mapping['o'].push_back('c');
        mapping['a'].push_back('o');
        mapping['a'].push_back('b');
        mapping['a'].push_back('c');
        mapping['b'].push_back('a');
        mapping['b'].push_back('c');
        mapping['b'].push_back('o');
        mapping['c'].push_back('a');
        mapping['c'].push_back('o');
        mapping['c'].push_back('b');
        return solve(N,'o',mapping);
        
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends
