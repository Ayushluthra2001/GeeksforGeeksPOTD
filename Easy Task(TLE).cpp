//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<char> easyTask(int n,string s,int q,vector<vector<string>> &queries){
        // Code here
        vector<char>ans;
        for(int i=0;i<q;i++){
            
            string type=queries[i][0];
            
            if(type=="1"){
                int index=stoi(queries[i][1]);
                // cout<<index<<endl;
                char change=queries[i][2][0];
                 
                 s[index]=change;
                
            }else{
                int left=stoi(queries[i][1]);
                int right=stoi(queries[i][2]);
                int k = stoi(queries[i][3]);
                // cout<<left<<" "<<right<<" "<<k<<" ";
                string sub=s.substr(left,right-left+1);
                sort(sub.begin(),sub.end());
                // cout<<sub<<endl;
                // cout<<s<<endl;
                for(int i=sub.length()-1;i>=0;i--){
                    if(k==1){
                        ans.push_back(sub[i]);
                        break;
                    }else{
                        k--;
                    }
                }
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
