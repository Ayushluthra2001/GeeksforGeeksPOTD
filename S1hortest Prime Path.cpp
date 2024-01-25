//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    int solve(int num1,int num2)
    {   
      vector<int> prime(10000,1);
      for(int i = 2;i*i<10000;i++){
          if(prime[i]){
              for(int j = 2*i;j<10000;j+=i)prime[j] = 0;
          }
      }
      
      unordered_set<int> st;
      for(int i = 1000;i<10000;i++) if(prime[i])st.insert(i);
      queue<pair<int,int>>q;
      q.push({0,num1});
      while(!q.empty()){
          int dist = q.front().first;
          int n = q.front().second;
          q.pop();
          if(n== num2) return dist;
          string num = to_string(n);
          for(int i = 0;i<4;i++){
              for(int j = 0;j<=9;j++){
                  char c = num[i];
                  num[i] = ('0' + j);
                  int nNum = stoi(num);
                  if(st.find(nNum) != st.end()){
                      st.erase(nNum);
                      if(num2 == nNum) return dist+1;
                      q.push({dist+1,nNum});
                  }
                  num[i] = c;
              }
          }
      }
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int num1,num2;
      cin>>num1>>num2;
      Solution obj;
      int answer=obj.solve(num1,num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends
