/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node *compute(Node *head) {
        // code here
        vector<int>temp;
        Node* root = head;
        while(root != NULL){
            temp.push_back(root->data);
            root = root->next;
        }
        int i = temp.size()-1;
        while(i>=0){
            int j = i-1;
            while(j>=0 && temp[i] > temp[j]) {
                temp[j] = -1;
                j--;
            }
            i = j;
        }
        Node* ans = new Node(-1);
        root = ans;
        for(auto i : temp) {
            if(i==-1){
                continue;
            }else {
                root->next = new Node(i);
                 root = root->next;
            }
        }
        
        return ans->next;
        
    }
};
