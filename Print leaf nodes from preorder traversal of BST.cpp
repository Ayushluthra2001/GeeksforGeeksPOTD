//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leafNodes(int arr[],int N) {
       stack<int>s;
       vector<int>ans;
       s.push(arr[0]);
       for(int i=1;i<N;i++){
           if(arr[i]<s.top())s.push(arr[i]);
           else {
               int temp=s.top();
               int counter=0;
               while(!s.empty() &&s.top()<arr[i]) s.pop(),counter++;
               s.push(arr[i]);
            if(counter>=2) ans.push_back(temp);
           }
           
       }
      
      
      ans.push_back(s.top());
      return ans;
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
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
