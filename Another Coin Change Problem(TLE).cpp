//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    
    int solve(int n , int k , int target,vector<int>&coins,int curr,int c){
        if(curr>target || c>k) return 0;
        if(curr==target && c!=k) return 0;
        if(curr!=target && c==k) return 0;
        if(curr==target && c==k) return 1;
        int count=0;
        for(int i=0;i<coins.size();i++){
            count+=solve(n,k,target,coins,curr+coins[i],c+1);
            
        }
        return count;
    }
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        // code here
        return solve(N,K,target,coins,0,0);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends
