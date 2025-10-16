/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  Node* solve(Node* root, int l , int r){
      if(root == NULL) return NULL;
      
      root->left = solve(root->left , l , r);
      root->right = solve(root->right , l , r);
      if(root->data < l) return root->right;
      else if(root->data > r) return root->left;
      
      return root;
  }
    Node* removekeys(Node* root, int l, int r) {
        // code here
        
        
        return solve(root, l , r);
    }
};
