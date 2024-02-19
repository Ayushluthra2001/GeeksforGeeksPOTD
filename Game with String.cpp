//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        unordered_map<char,int>mapping;
        for(auto i : s){
            mapping[i]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto i :mapping){
            pq.push({i.second,i.first});
        }
        while(k>0 && !pq.empty()){
            pair<int,int>p=pq.top();
            pq.pop();
            if(p.first>1){
                int temp=p.first;
                temp=temp-1;
                pq.push({temp,p.second});
            }
            k--;
        }
        if(pq.size()==0){
            return 0;
        }
    int sum=0;
        while(!pq.empty()){
            int t=pq.top().first;
            pq.pop();
            sum+=t*t;
            
        }
        return sum;
    }
    
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
