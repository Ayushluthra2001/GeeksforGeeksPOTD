//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    // function to construct tree from string
    Node* fun(string &s, int &i){
        int n=s.size();
        int v=0;
        for(;i<n and (s[i]>='0' and s[i]<='9');i++){
            v=v*10+(s[i]-'0');
        }
        Node* root= new Node(v);
        if(s[i]=='('){
            // skip opening bracket
            i++;
            root->left=fun(s, i);
        }
        if(s[i]=='('){
            // skip opening bracket
            i++;
            root->right=fun(s, i);
        }
        // skip closing bracket
        i++;
        return root;
    }
    Node *treeFromString(string str){
        int i=0;
        return fun(str, i);
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
