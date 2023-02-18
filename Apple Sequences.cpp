//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr) {
        int j = 0, orange = 0, maxi = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] == 'O') orange++;
            while(orange > m) {
                if(arr[j] == 'O') orange--;
                j++;
            }
            maxi = max(maxi, i - j + 1);
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
