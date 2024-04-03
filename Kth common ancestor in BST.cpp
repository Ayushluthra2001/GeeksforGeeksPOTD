class Solution
{
    public:
    
    /*You are required to complete below function */
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
        // your code goes here
        vector<int> vec;
        
        while(true){
            vec.push_back(root->data);
            
            if(x>root->data && y>root->data)
                root=root->right;
            else if(x<root->data && y<root->data)
                root=root->left;
            else
                break;
        }
        int ind=vec.size()-k;
        if(vec.size() <k)
            return -1;
        return vec[ind];
    }
};
