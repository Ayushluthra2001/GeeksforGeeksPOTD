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
  
    void reverse(Node*& root){
        if(root == NULL) return ;
        Node* curr = root;
        Node* prev = NULL;
        Node* next = curr;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            
           
        }
        root = prev;
        
    }
   
    Node *compute(Node *head) {
        // code here
        reverse(head);
        
        Node* temp = head;
        while(temp!=NULL){
            if(temp->next){
                Node* temp2 = temp->next;
                while(temp2!= NULL && temp->data > temp2->data){
                    temp2 = temp2->next;
                    
                }
                temp->next = temp2;
                temp = temp2;
            }else break;
        }
        reverse(head);
        return head;
        
        
    }
};
