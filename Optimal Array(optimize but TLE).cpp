//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> optimalArray(int n,vector<int> &a){
            // Code here
    
        sort(a.begin(),a.end());
      
        vector<int>ans;
        int i=0;
        int j=0;
        
        while(j<a.size()){
            
            
            int mid=0+j/2;
            int el=a[mid];
            int count=0;
            for(int k=0;k<=j;k++){
                count+=abs(a[k]-el);
            }
            ans.push_back(count);
            j++;
        }
       
        return ans;
    }
};



//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution obj;
        vector<int> ans=obj.optimalArray(n,a);
        for(auto ele:ans){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
