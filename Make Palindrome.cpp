//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
        // Code here
        int siz = arr[0].size();
        unordered_map<string,int> ump;
        for(auto x:arr){
            ump[x]++;
        }
        for(int i=0;i<n;i++){
            string str = arr[i];
            string s = str;
            reverse(s.begin(),s.end());
            if(ump[s]!=0){
                if(s!=str){
                    ump[s]--;
                    ump[str]--;
                }
                else if(s==str){
                    ump[s]=ump[s]%2;
                }
            }
        }
        int cnt=0;
        for(auto x:ump){
            string str = x.first;
            string s = str;
            reverse(s.begin(),s.end());
            if(x.second>0){
                if(s==str&&x.second==1){
                    cnt++;
                }
                else{
                    return false;
                }
            }
        }
        if(cnt<2){
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends
