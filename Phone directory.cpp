//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Node{
public: 
    char data;
    Node *s[26];
    set<string> store;
    Node(char val){
        data = val;
        for(int i=0;i<26;i++){
            s[i]=NULL;
        }
    }
};

void Insert(Node *head,string st){
    Node *p = head;
    for(int i=0;i<st.length();i++){
        int ind = st[i]-'a';
        if(p->s[ind]==NULL){
            p->s[ind]=new Node(ind+'a');
        }
        p->s[ind]->store.insert(st);
        p=p->s[ind];
    }
}

vector<string> Search(Node *head,string t){
    Node *p = head;
    vector<string> direc;
    for(int i=0;i<t.length();i++){
        int ind = t[i]-'a';
        if(p->s[ind]==NULL){
            return {"0"};
        }
        p=p->s[ind];
    }
    set<string> h = p->store;
    vector<string> res;
    for(auto x:h){
        res.push_back(x);
    }
    return res;
}

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>> ans;
        Node *head = new Node('-');
        for(int i=0;i<n;i++){
            string st = contact[i];
            Insert(head,st);
        }
        
        string tp;
        for(int i=0;i<s.length();i++){
            tp += s[i];
            vector<string> help;
            help = Search(head,tp);
            ans.push_back(help);
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
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
