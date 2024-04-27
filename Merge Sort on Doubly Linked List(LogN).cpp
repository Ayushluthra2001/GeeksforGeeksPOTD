//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends

/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

class Solution {
  public:
  struct Node* merge(struct Node* first, struct Node* second){
      if(first==NULL) return second;
      if(second==NULL) return first;
      struct Node* dummy=new Node(-1);
      struct Node* temp=dummy;
     
      while(first!=NULL && second!=NULL){
        if(first->data>=second->data){
        
            temp->next=second;
            second->prev=temp;
            second=second->next;
        }else{
           temp->next=first;
           first->prev=temp;
           first=first->next;
        }
        temp=temp->next;
        
      }
     if(first!=NULL){
         temp->next=first;
         first->prev=temp;
     }
     if(second!=NULL){
         temp->next=second;
         second->prev=temp;
     }
     struct Node* ans=dummy->next;
     ans->prev=NULL;
     return ans;
  }
  struct Node* funSplit(struct Node* h){
      struct Node* slow=h;
      struct Node* fast=h;
      while(fast->next!=NULL && fast->next->next!=NULL){
          slow=slow->next;
          fast=fast->next;
          fast=fast->next;
      }
      struct Node* temp= slow->next;
      slow->next=NULL;
      return temp;
  }
    // Function to sort the given doubly linked list using Merge Sort.
    struct Node *sortDoubly(struct Node *h1) {
        // Your code here
        if(h1==NULL || h1->next==NULL) return h1;
        Node* h2=funSplit(h1);
        h1=sortDoubly(h1);
        h2=sortDoubly(h2);
        return merge(h1,h2);
    }
};


//{ Driver Code Starts.

void insert(struct Node **head, int data) {
    struct Node *temp = new Node(data);
    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(struct Node *head) {
    struct Node *temp = head;
    while (head) {
        cout << head->data << ' ';
        temp = head;
        head = head->next;
    }
    cout << endl;
    while (temp) {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << endl;
}

// Utility function to swap two integers
void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}

// Driver program
int main(void) {
    long test;
    cin >> test;
    while (test--) {
        int n, tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            insert(&head, tmp);
        }
        Solution ob;
        head = ob.sortDoubly(head);
        print(head);
    }
    return 0;
}

// } Driver Code Ends
