/* Structure for Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
  int solve(Node* root){
      if(root == NULL) return 0 ;
      if(root->left == NULL && root->right == NULL){
         int val = root->data;
         root->data = 0;
         return val;
      }
      int left = solve(root->left);
      int right = solve(root->right);
      int c = root->data;
      root->data = left + right;
      return root->data+c;
  }
    void toSumTree(Node *root) {
        // code here
        
        
        solve(root);
        
    }
};
