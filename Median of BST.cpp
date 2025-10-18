/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  void solve(Node* root ,vector<int>&data){
      if(root == NULL) return ;
      
      solve(root->left, data);
      data.push_back(root->data);
      solve(root->right , data);
  }
    int findMedian(Node* root) {
        // Code here
        vector<int>data;
        solve(root, data);
        
        if(data.size()%2 == 0){
            return data[(data.size()/2)-1];
        }else{
            return data[(data.size()/2)];
        }
        return 0;
        
    }
};
