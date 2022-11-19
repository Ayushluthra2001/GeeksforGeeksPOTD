//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

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
//User function Template for C++

class Solution{
    public:
    bool areAnagrams(Node *root1, Node *root2)
    {
        vector<vector<int>>roots1;
        vector<vector<int>>roots2;
        queue<Node* >q1,q2;
        q1.push(root1);
        q2.push(root2);
        while(!q1.empty()){
            int size=q1.size();
            vector<int>temp;
            for(int i=0;i<size;i++){
                Node* front=q1.front();
                temp.push_back(front->data);
                q1.pop();
                if(front->left)
                q1.push(front->left);
                if(front->right)
                q1.push(front->right);
                
            }
            sort(temp.begin(),temp.end());
            roots1.push_back(temp);
            
            
        }
        while(!q2.empty()){
            int size=q2.size();
            vector<int>temp;
            for(int i=0;i<size;i++){
                Node* front=q2.front();
                q2.pop();
                temp.push_back(front->data);
                if(front->left)
                q2.push(front->left);
                if(front->right)
                q2.push(front->right);
                
            }
            sort(temp.begin(),temp.end());
            roots2.push_back(temp);
            
            
        }
        // for(auto i : roots1){
        //     for(auto j:i)
        //     cout<<j<<" ";
        //     cout<<endl;
        // }
        if(roots1.size()!=roots2.size()) return false;
        
        for(int i=0;i<roots1.size();i++){
            if(roots1[i].size()!=roots2[i].size()) {return false;}
            
            for(int j=0;j<roots1[i].size();j++){
            
                if(roots1[i][j]!=roots2[i][j]) return false;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);
        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);
        Solution ob;
        cout << ob.areAnagrams(root1, root2) << endl;
    }
    return 0;
}

// } Driver Code Ends
