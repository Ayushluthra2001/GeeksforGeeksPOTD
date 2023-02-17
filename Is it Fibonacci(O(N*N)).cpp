//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        // code here
        if(K==1) return GeekNum[0];
         
       
        
     
        for(int i=0;i<N;i++){
            if(i>K-1){
                long long sum=0;
                int curr=i-1;
                int j=0;
                while(curr>=0 && j<K){
                    sum+=GeekNum[curr];
                    curr--;
                    j++;
                }
                GeekNum.push_back(sum);
                
            }    
        }
        // for(auto i : GeekNum){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        return GeekNum[N-1];
    }
};
// 7 3
// 96 54 17


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends
