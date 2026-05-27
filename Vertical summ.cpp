/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution {
  public:
  
  void solve(vector<int>& ans, map<int,int>&mapping,int currLevel, Node* root){
      if(root == NULL) return ;
      
      // left 
      solve(ans, mapping,currLevel-1, root->left);
      
      mapping[currLevel]+=root->data;
      // right
      solve(ans, mapping, currLevel+1, root->right);
      return ;
  }
    vector<int> verticalSum(Node* root) {
        // code here
        
        vector<int>ans;
        map<int,int>mapping;
        solve(ans, mapping, 0, root);
        
        for(auto i : mapping){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};
