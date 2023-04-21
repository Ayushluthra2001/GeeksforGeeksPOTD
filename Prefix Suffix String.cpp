//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

typedef struct Trie{
        Trie* children[26];
} Trie;


class Solution{
public:


    void insert(Trie* root, string s){
        Trie* curr=root;
        for(char ch: s){
            int ind=ch-'a';
            if(curr->children[ind]==NULL){
                curr->children[ind]=new Trie();
            }
            curr=curr->children[ind];
        }
    }


    bool search(Trie* root, string s){
        Trie* curr=root;
        for(char ch: s){
            int ind=ch-'a';
            if(curr->children[ind]==NULL){
                return false;
            }
            curr=curr->children[ind];
        }
        return true;
    }


    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        
        Trie* root=new Trie();
        int count=0;


        for(int i=0; i<s1.size(); i++){
            string s=s1[i];
           insert(root,s);
           reverse(s.begin(), s.end());
           insert(root,s);
        }


        for(int i=0; i<s2.size(); i++){
            string s=s2[i];
            if(search(root,s)){
                count++;
                continue;
            }
            reverse(s.begin(), s.end());
            if(search(root,s)){
                count++;
            }
        }


        return count;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends
