//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        // code here
        
       
        
        Node* temp   = head;
        Node* result = new Node(-1);
        Node* temp2  = result;
        
        while( temp != NULL)  {
            bool find = false;
            if(temp -> next != NULL){
                Node * temp3 = temp -> next;
                while(temp3!=NULL && temp->data == temp3->data){
                    temp3 = temp3 ->next;
                    find = true;
                }
                if(find)
                temp = temp3;
            }
            if(!find){
                temp2 -> next = new Node(temp -> data);
                temp2 = temp2 -> next;
                temp  = temp  -> next;
            }
        }
        
      
        return result -> next;
        
    }
};

//{ Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;

        cin >> N;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < N; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        head = ob.removeAllDuplicates(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
