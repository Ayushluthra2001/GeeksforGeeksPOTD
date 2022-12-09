//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
bool isValid(int i, int j, int &N, int &M){
    return i>=0 && i<N && j>=0 && j<M;
}

int solve(int i, int j, int &N, int &M){
    long long count = 0;
    
    if(isValid(i-2,j+1,N,M)){
        count++;
    }
    
    if(isValid(i-2,j-1,N,M)){
        count++;
    }
    
    if(isValid(i-1,j+2,N,M)){
        count++;
    }
    
    if(isValid(i+1,j+2,N,M)){
        count++;
    }
    
    if(isValid(i+2,j+1,N,M)){
        count++;
    }
    
    if(isValid(i+2,j-1,N,M)){
        count++;
    }
    
    if(isValid(i-1,j-2,N,M)){
        count++;
    }
    
    if(isValid(i+1,j-2,N,M)){
        count++;
    }
    
    return N*M - count - 1;
}

long long numOfWays(int N, int M){
    long long ans = 0;
    long long mod = 1e9+7;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            ans = (ans + solve(i,j,N,M))%mod;
        }
    }
    
    return ans;
}
