//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
      if(N<=K) return GeekNum[N-1]; 
      int index=-1;
      long long sum=0;
      for(int i=0;i<K;i++){
          sum+=GeekNum[i];
      }
      
      for(int i=K;i<N;i++){
          if(i==K){
              GeekNum.push_back(sum);
              index=0;
          }else{
                long long currsum=sum+sum;
              
              currsum-= index>=0 ? GeekNum[index] :0;
              GeekNum.push_back(currsum);
              sum=currsum;
              index++;    
          }
          
          
      }
    //   for(auto i : GeekNum){
    //       cout<<i<<" ";
          
    //   }
    //   cout<<endl;
      return GeekNum[N-1];
        
    }
};


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
