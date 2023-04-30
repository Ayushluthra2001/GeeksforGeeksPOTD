//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        map<int , int>mp; //index , and freq
        for(auto it : intervals){
            int left = it[0];
            int right= it[1];
            mp[left]++;
            mp[right + 1]--;
        }
        int prefixSum = 0;
        int ans = -1;
        bool flag = false;
        for(auto it : mp){
            prefixSum += it.second; // calculating prefix sum 
            if(prefixSum >= k){
                ans = it.first;
                flag = true;
            }
            else if( flag == true ){
                ans = it.first - 1;
                flag = false;
            }else{
                flag = false;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
