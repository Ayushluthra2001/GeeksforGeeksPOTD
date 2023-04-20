//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

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
    Node* root = newNode(stoi(ip[0]));
        
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
            currNode->left = newNode(stoi(currVal));
                
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
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{
    
    void mark_parents(Node*root , unordered_map<Node* , Node*>&parent)
    {
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            Node*f = q.front();
            q.pop();
            
            if(f)
            {
                if(f->left)
                {
                    q.push(f->left);
                    parent[f->left]=f;
                }
                if(f->right)
                {
                    q.push(f->right);
                    parent[f->right]=f;
                }
            }
            else
            {
                if(!q.empty())q.push(NULL);
            }
        }
    }
    
    Node*search_home(int home , Node*root)
    {
        if(!root)return NULL;
        
        if(root->data == home)return root;
        
        Node*left = search_home(home , root->left);
        if(left)return left;
        
        return search_home(home , root->right);
    }
    
    public:
    int ladoos(Node* root, int home, int k)
    {
        unordered_map<Node* , Node*>parent;
        mark_parents(root , parent);
        
        Node*target  = search_home(home , root);
        
        queue<Node*>q;
        q.push(target);
        unordered_map<Node* , bool>visited;
        visited[target]=true;
        int sum=0;
        sum+=home;
        int curr_level = 0;
        
        while(!q.empty())
        {
            int n=q.size();
            if(curr_level++ == k)break;
            for(int i=0 ; i<n ; i++)
            {
                Node*f=q.front();
                q.pop();
                
                if(f->left and !visited[f->left])
                {
                    q.push(f->left);
                    sum+=f->left->data;
                    visited[f->left]=true;
                }
                if(f->right and !visited[f->right])
                {
                    q.push(f->right);
                    sum+=f->right->data;
                    visited[f->right]=true;
                }
                if(parent[f] and !visited[parent[f]])
                {
                    q.push(parent[f]);
                    sum+=parent[f]->data;
                    visited[parent[f]]=true;
                }
            }
        }
        
        return sum;
        
    }


};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends
