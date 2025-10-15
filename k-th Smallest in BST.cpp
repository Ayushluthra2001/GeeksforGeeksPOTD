/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  void solve(vector<int>& inorder , Node* root){
      if(root == NULL) return ;
      
      solve(inorder, root->left);
      inorder.push_back(root->data);
      solve(inorder, root->right);
  }
    int kthSmallest(Node *root, int k) {
        // code here
        vector<int>inorder;
        
        solve(inorder, root);
        
        if(inorder.size() < k) return -1;
        
        return inorder[k-1];
        
    }
};
