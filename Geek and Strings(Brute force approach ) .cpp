//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    int check(string prefix, string x){
        if(prefix.length()>x.length()) return 0;
        for(int i=0;i<prefix.length();i++){
            if(prefix[i]!=x[i]) return 0;
        }
        return 1;
    }
public:
    vector<int> prefixCount(int N, int Q, string li[], string query[])
    {
        
        vector<int>ans;
        for(int i=0;i<Q;i++){
            int count=0;
            for(int j=0;j<N;j++){
                
                if(check(query[i],li[j])) count++;
            }
            ans.push_back(count);
        }
    return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int Q, N, i = 0, x;
	    cin>>N;
	    string s;
	    string li[N];
	    for(int i = 0;i < N;i++)
	        cin>>li[i];
	    cin>>Q; 
	    x = Q;
	    string query[Q];
	    while(Q--){
	        cin>>s;
	        query[i++] = s;
	    }
	    
	    Solution ob;
	    vector<int> ans = ob.prefixCount(N, x, li, query);
	    for(auto i: ans) 
	        cout<<i<<"\n";
    }
    return 0;
}
// } Driver Code Ends
