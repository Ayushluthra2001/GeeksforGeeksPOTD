//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    int goodStones(int n,vector<int> &v){
       // unordered_map<int,int>m;
        vector<bool>s(n,false);
        set<int>a;
        int h=0;
        for(int i=0;i<n;i++){
            if(!s[i]){
               vector<int>k;
               int p=0;
                int des=i;
                while(!s[des]){
                    k.push_back(des);
                    s[des]=true;
                    des += v[des];
                    if(des>=n || des<0){
                       while(p<k.size()){
                          // cout<<k[p]<<" ";
                           a.insert(k[p]);
                           p++;
                       }
                    break;
                    }
                    if(p<k.size() && a.count(des)){
                        for(auto j : k)a.insert(j);
                    }
                    }
             
        }
        }
        return a.size();
    }  
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
