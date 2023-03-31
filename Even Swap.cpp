//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            // Code here
            
            priority_queue<int> pq;
            pq.push(a[n-1]);
            int i = n-2;
            while(i>=0){
                int val = pq.top();
              
                if((val+a[i])%2==0){
                   
                    pq.push(a[i]);
                    i--;
                    continue;
                }
                else{
                    int k = i+1;
                    while(!pq.empty()){
                        int top1 = pq.top();
                        a[k++] = top1;
                        pq.pop();
                    }
                    pq.push(a[i]);
                    i--;
                }
            }
            int k =0;
            while(!pq.empty()){
                        int top1 = pq.top();
                       
                        a[k++] = top1;
                        pq.pop();
                    }
            return a;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
