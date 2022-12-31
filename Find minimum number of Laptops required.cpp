//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minLaptops(int N, int start[], int end[]) {
        vector<pair<int,int>>ans;
        for(int i=0;i<N;i++){
            ans.push_back({start[i],end[i]});
            
        }
        sort(ans.begin(),ans.end());
        int count=1;
        priority_queue<int , vector<int>,greater<int>>pq;
        pq.push(ans[0].second);
        for(int i=1;i<N;i++){
            int s=ans[i].first;
            int e=ans[i].second;
            if(pq.top()<=s){
                pq.pop();
                
            }else{
                count++;
            }
            pq.push(e);
            
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends
