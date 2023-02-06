//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};




// } Driver Code Ends
//User function Template for C++
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
public:
    int find=-1;
    void finding(Node* root, int target,unordered_map<int,vector<int>>&mapping){
        if(root==NULL)  return; 
        if(root->data==target){
             solve(mapping,root,0,target);
        }
        else if(root->data> target){
            finding(root->left,target,mapping);
        }else{
            finding(root->right,target,mapping);
        }
    }
    void solve(unordered_map<int,vector<int>>&mapping, Node* root,int level,int target){
        if(root==NULL) return ;
        if(root->data==target) find=level;
        mapping[level].push_back(root->data);
        solve(mapping,root->left,level-1,target);
        solve(mapping,root->right,level+1,target);
    }
    long long int verticallyDownBST(Node *root,int target){
        // Code here
        unordered_map<int,vector<int>>mapping;
        finding(root,target,mapping);
       
        if(find==-1) return -1;
        vector<int>temp=mapping[find];
        long long int sum=0;
        bool gotit=false;
        for(int i=0;i<temp.size();i++){
            
            if(gotit){
                sum+=temp[i];
                
            }else if(!gotit && target==temp[i]){
              
                gotit=true;
            } 
        }
        return sum;
    }
};

//{ Driver Code Starts.

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

void inorder(Node *root, vector<int> &v)
{
    if(root==NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {
 
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        int target;
        cin>>target;
        string newline;
        getline(cin,newline);
        string s; 
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout<<ob.verticallyDownBST(root, target)<<endl;
   }
   return 0;
}
// } Driver Code Ends
