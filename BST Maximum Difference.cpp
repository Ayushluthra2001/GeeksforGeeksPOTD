//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
int ans=-1e9-7;
int solve(Node *root,int t,int path){
    if(root==NULL)return 0;
    if(root->left==NULL&&root->right==NULL){
        if(root->data==t)ans=max(ans,path);
        return root->data;
    }
    int tmp=1e9+7;
    if(root->left)tmp=min(tmp,solve(root->left,t,path+root->data));
    if(root->right)tmp=min(tmp,solve(root->right,t,path+root->data));
    if(root->data==t)ans=max(ans,path-tmp); 
    
    return root->data+tmp;
}
    int maxDifferenceBST(Node *root,int t){
     solve(root,t,0); 
     if(ans<=-1e9-7)return -1;
     return ans;
    }
};
//       8
//             20 
//          15      19
//         9    17         20
// };        10

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends
