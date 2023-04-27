//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
// {{"2","1","3","1"}}
//bdb
//b = 2
//d = 1
    vector<char> easyTask(int n,string s,int q,vector<vector<string>> &queries){
      
      vector<char> v;
      
      for(int i=0;i<q;i++) {
          
          if(queries[i][0]=="1") {
              int index=stoi(queries[i][1]);
               s[index]=queries[i][2][0];
          }
          else {
              
              int start=stoi(queries[i][1]);
              int end=stoi(queries[i][2]);
              int k=stoi(queries[i][3]);
             
             int freq[26]={0};
                 int count=0 ;
                 
             for(int j=start;j<=end;j++ ) {
                 freq[s[j]-'a']++;
             }
             
             for(int j=25;j>=0;j--) {
                 count+=freq[j];
                 if(count>=k)
                 {
                     count=j+'a';
                     break;
                 }
             }
            
              v.push_back(count);
        
          }
      }
    
      return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int q;
        cin>>q;
        vector<vector<string>> queries(q);
        for(int i=0;i<q;i++){
            string x;
            cin>>x;
            if(x=="1"){
                string p,q;
                cin>>p>>q;
                queries[i]={"1",p,q};
            }
            else{
                string p,q,r;
                cin>>p>>q>>r;
                queries[i]={"2",p,q,r};
            }
        }
        Solution ob;
        vector<char> ans=ob.easyTask(n,s,q,queries);
        for(auto ch:ans){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends
