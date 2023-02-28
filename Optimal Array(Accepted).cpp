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

        vector<int>ans;

        ans.push_back(0);

        for(int i=1;i<n;i++)

        {

            int mid1=i/2,mid2=(i+1)/2;

            int val1;

            val1=(ans.back()+a[i]-a[mid1]);

            int val2;

            val2=a[mid2]-a[mid1];

            val2=(i*val2)+a[i]-a[mid2]+ans.back();

            ans.push_back(min(val1,val2));

            

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
