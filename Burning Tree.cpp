//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


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
class Solution {
  public:
  
  int  burnTree(unordered_map<Node* , Node*>&mapping,unordered_map<int,int>&visited,Node* curr){
     int ans = 0;
     queue<Node*>q;
     q.push(curr);
     
     while(!q.empty()){
         int size = q.size();
         
         bool flag = 0;
        
         for(int i= 0;i<size;i++){
             Node* front = q.front();
             q.pop();
             
             visited[front->data] = true;
             
             if(front->left!=NULL && !visited[front->left->data]){
                 flag = 1;
                 visited[front->left->data] = 1;
                 q.push(front->left);
             }
             if(front->right!=NULL && !visited[front->right->data]){
                 flag = 1;
                 visited[front->right->data] = 1;
                 q.push(front->right);
             }
             
             if(mapping[front] !=NULL && !visited[mapping[front]->data]){
                 flag = 1;
                 visited[mapping[front]->data] = 1;
                 q.push(mapping[front]);
             }
         }
         if(flag) ans++;
         
     }
     
     return ans;
      
      
      
  }
    void solve(Node* root, unordered_map<Node* , Node* >&mapping){
            
            if(root== NULL) return; 
            if(root->left != NULL ){
                mapping[root->left] = root;
                
            }
            if(root->right != NULL){
                mapping[root->right] = root;
            }
            solve(root->left,mapping);
            solve(root->right,mapping);
            
            
    }
    Node*  findTarget(Node* root, int target){
        if(root==NULL) return NULL ;
        if(target==root->data) {
            
            return root;
        }
        Node* left =findTarget(root->right,target);
        Node* right = findTarget(root->left , target);
        if(right != NULL) return right;
        if(left !=NULL) return left ;
        return NULL;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node* , Node* > mapping;
      
        solve(root,mapping);
        mapping[root] = NULL;
        
        
        Node * targetNode = NULL;
        targetNode = findTarget(root,target);
        
        
        
        unordered_map<int,int>visited;
       
        return burnTree(mapping,visited,targetNode);
        
        
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends
