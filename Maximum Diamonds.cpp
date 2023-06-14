//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long maxDiamonds(int A[], int N, int k) {
        // code here
        priority_queue<long long>pq;
        for(int i=0;i<N;i++){
            pq.push(A[i]);
        }
        long long maxi=0;
        while(!pq.empty() && k--){
            long long x=pq.top();
            pq.pop();
            
            if(x%2==0){
                maxi+=x;
                pq.push(x/2);
            }else{
                maxi+=x;
                pq.push((x/2));
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.maxDiamonds(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends
