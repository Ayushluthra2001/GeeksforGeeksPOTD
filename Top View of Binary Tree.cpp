class Solution {
  public:
  
    void solve(Node* root, int hd, int depth, map<int, pair<int,int>>& mp){
        if(root == NULL) return;
        
        if(mp.find(hd) == mp.end() || depth < mp[hd].first){
            mp[hd] = {depth, root->data};
        }
        
        solve(root->left, hd-1, depth+1, mp);
        solve(root->right, hd+1, depth+1, mp);
    }
  
    vector<int> topView(Node *root) {
        
        map<int, pair<int,int>> mp;
        solve(root, 0, 0, mp);
        
        vector<int> ans;
        
        for(auto &i : mp){
            ans.push_back(i.second.second);
        }
        
        return ans;
    }
};
