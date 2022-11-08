//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        map<long long int,long long int>mapping;
        vector<long long int>ans;
        
        for(int i=0;i<N;i++){
            mapping[Arr[i]]++;
        }
         long long int first,second;
         bool flag=false;
        for(auto i : mapping){
            if(i.second%2!=0 && !flag){
                first=i.first;
                flag=true;
            }else if(flag && i.second%2!=0){
                second=i.first;
            }
        }
        if(first>second){
            return{first,second};
        }
        return {second,first};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
