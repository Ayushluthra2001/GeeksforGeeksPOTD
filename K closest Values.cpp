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
void solve(Node* root , int target , int k, map<int,vector<int>>&mapping ){
    
    
    if(root == NULL) return;
    
    solve(root->left, target , k , mapping);
    
    
    int find = abs(root->data - target);
    mapping[find].push_back(root->data);
    solve(root->right, target , k , mapping);
    
}
    vector<int> getKClosest(Node* root, int target, int k) {
        // code here
        map<int,vector<int>>mapping;
        
        vector<int>ans;
        solve(root, target,k, mapping);
        
        for(auto i : mapping){
            sort(i.second.begin(),i.second.end());
            for(auto j : i.second){
                ans.push_back(j);
                if(ans.size() == k) return ans;
            }
        }
        return ans;
    }
};
