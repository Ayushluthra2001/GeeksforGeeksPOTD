//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


// } Driver Code Ends
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution{
  public:
  void solve(unordered_set<int>&leaf,Node* root){
      if(root==NULL) return ;
      solve(leaf,root->left);
      if(root->left==NULL && root->right==NULL) {
          leaf.insert(root->data);
          return;
      }
      
      solve(leaf,root->right);
  }
  void solve2(unordered_set<int>&st, Node* root){
      if(root==NULL) return;
      solve2(st,root->left);
      st.insert(root->data);
      
      solve2(st,root->right);
  }
    bool isDeadEnd(Node *root)
    {
        //Your code here
        Node* temp=root;
        unordered_set<int>leaf,st;
        solve(leaf,temp);
        temp=root;
        solve2(st,temp);
        st.insert(0);
        // for(auto i : leaf){
        //     cout<<i<<" ";
        // }cout<<endl;
        // for(auto i : st){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        for(auto i : leaf){
             auto x =i;
            // cout<<i<<" ";
            // if(st.find(x-1)!=st.end()){
            //     cout<<" find"<<endl;
            // }
            // if(st.find(x+1)!=st.end()){
            //     cout<<" fined"<<endl;
            // }
            if(st.find(x-1)!=st.end() && st.find(x+1)!=st.end()) return true;
        }
       // cout<<endl;
        return false ;
    }
};

//{ Driver Code Starts.
// bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

     Solution ob;
     cout<<ob.isDeadEnd(root);
     cout<<endl;
    }
}


// } Driver Code Ends
