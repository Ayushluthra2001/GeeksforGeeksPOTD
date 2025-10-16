/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
    void solve(vector<int>& ans, Node* root){
        if(root == NULL) return;
        
        solve(ans, root->left);
        ans.push_back(root->data);
        solve(ans, root->right);
        
    }
    void oldToNewValue(unordered_map<int,int>&mapping, Node* root){
        if(root == NULL) return;
        
        oldToNewValue(mapping, root->left);
        root->data = mapping[root->data];
        oldToNewValue(mapping,root->right);
    }
    void transformTree(Node *root) {
        // code here
        
        // storing inorder traversal of bst
        vector<int>ans;
        solve(ans, root);
        
        
        
        // 1 2 7 11 15 29 35 40 -> o(N) , O(N)
        // 139 137 130 119 104 75 0 -> O(N)
        // 1 -> 139 oldvalue - > new value O(N)
        // Overall Time Commplexity and Space Complexity O(N)
        
        // creating hashmap which store the sum all greater element from current element
        unordered_map<int,int>mapping;
        int sum = ans[ans.size()-1];
        mapping[ans[ans.size()-1]] = 0;
        
        for(int i =ans.size()-2; i >=0; i--){
          mapping[ans[i]] = sum;
          sum+=ans[i];
        }
        oldToNewValue(mapping,root);
        return ;
        
        
        
        
    }
};
