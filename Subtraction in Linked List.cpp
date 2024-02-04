//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
     pair<Node*,int> rev(Node* head){
        Node* curr = head;
        Node* prev = nullptr;
        int len = 0;
        while(curr)
        {
            Node*temp=curr->next;
            curr->next=prev;
            
            prev=curr;
            curr=temp;
            len++;
        }
        return {prev,len};
    }
    
    bool isLarger(Node*head1,Node*head2){
        Node*temp1=head1;
        Node*temp2=head2;
        
        while(temp1 and temp2 and (temp1->data==temp2->data)){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        if(!temp1)return 0;
        
        if(temp2->data > temp1->data)return 1;
        return 0;
    }
    
    Node* removeLeadingZero(Node* head){
        while(head->next && head->data==0)head=head->next;
        return head;
    }
    
    Node* subLinkedList(Node* head1, Node* head2) {
        
        head1 = removeLeadingZero(head1);
        head2 = removeLeadingZero(head2);
        
        
        pair<Node*,int> inp;
        int len1,len2;
        
        bool flag = isLarger(head1,head2);
        
        inp = rev(head1);
        head1=inp.first;
        len1=inp.second;
        
        inp = rev(head2);
        head2=inp.first;
        len2=inp.second;
        
        if((len2>len1) or (len1==len2 and flag)){
            Node*temp=head1;
            head1=head2;
            head2=temp;
        }
        
        bool carry = 0;
        Node*res=new Node(-1);
        Node* temp=res;
        while(head1 and head2){
            
            if(head1->data > head2->data){
                if(carry)
                {
                   carry=0;
                   head1->data--;
                }
                temp->next=new Node(head1->data-head2->data);
                temp=temp->next;
            }
            else if(head1->data == head2->data and !carry){
                temp->next=new Node(head1->data-head2->data);
                temp=temp->next;
            }
            else{
                if(carry){
                    head1->data+=10;
                    head1->data-=1;
                }
                else
                {
                    head1->data+=10;
                    carry=1;
                }
                temp->next=new Node(head1->data-head2->data);
                temp=temp->next;
            }
            head1=head1->next;
            head2=head2->next;
        }
        
        while(head1){
            if(head1->data > 0){
                if(carry)
                {
                   carry=0;
                   head1->data--;
                }
                temp->next=head1;
                break;
            }
            else{
                if(carry){
                    head1->data+=10;
                    head1->data-=1;
                }
                temp->next=new Node(head1->data);
                temp=temp->next;
            }
            head1=head1->next;
        }
        
        inp =  rev(res->next);
        res = inp.first;
        
        res = removeLeadingZero(res);
        
        return res;
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends
