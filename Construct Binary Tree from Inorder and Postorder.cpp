//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:

    //Function to return a tree created from postorder and inoreder traversals.
    void createMapping(int in[],unordered_map<int,int>&mapping, int n){
        for(int i=0;i<n;i++){
            mapping[in[i]]=i;
        }
        return ;
    }
    Node* solve(int in[],int post[],int &index, int start ,int end,unordered_map<int,int>&mapping){
         
        if( index<0 || start>end) return NULL;
        int el=post[index--];
        
        Node* root=new Node(el);
       int pos=mapping[el];
       
       root->right=solve(in, post, index, pos+1, end, mapping);
        root->left=solve(in, post, index, start, pos-1, mapping);
        
        return root;
    }
    Node *buildTree(int in[], int post[], int n) {
        // Your code here
        int index=n-1;
        unordered_map<int,int>mapping;
        createMapping(in,mapping, n);
        Node* ans=solve(in,post,index,0,n-1,mapping);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
