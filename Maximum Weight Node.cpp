//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge){
    vector<int> ans(N , 0);
    for(int i=0; i < N; i++){
        if(Edge[i] != -1) ans[Edge[i]] += i;
    }
    return max_element(ans.begin(), ans.end()) - ans.begin();
  }
};
// 5
// 2 3 4 4 2
// 0->2
// 1->3
// 2->4->0->4
// 3->1->4
// 4->4->2->3->2
// 2-



//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends
