//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//class Solution
struct Node {
    Node * links[26];
    bool end = false;
    bool contains(char c){
        return links[c - 'a'] != NULL;
    }
    void made(char c){
        links[c - 'a'] = new Node();
    }
    
    Node * goto_next(char c ){
        return links[c - 'a'];
    }
};
class Trie{
    public:
        Node *  root ;
        Trie(){
            root = new Node();
        }
        void insert(string & words){
            Node * node = root;
            for(auto it : words){
                if(node -> contains(it) == false){
                    node -> made(it);   
                }
                node = node -> goto_next(it);
            }
            node -> end = true;
        }
        bool search(string & words){
            Node * node = root;
            for(auto it : words){
                // cout << it << endl;
                if(node ->contains(it) == false){
                    return false;
                }
                node = node -> goto_next(it);
                if(!node -> end)return false;
            }
            return true;
        }
};
class Solution
{
public:
    string longestString(vector<string> &words)
    {
        // code here
        sort(words.begin() , words.end());
        Trie trie;
        string ans  = "";
        int len = 0;
        for(auto it : words){
            trie.insert(it);
            if(trie.search(it) and len < it.size()){
                len = it.size();
                ans = it;
            }
        }
        return ans;
    
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends
