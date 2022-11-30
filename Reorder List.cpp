//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{ 
public:
    void reorderList(Node* head) {
        
        // Your code here
        vector<int>el;
        Node* temp=head;
        while(temp!=NULL){
            el.push_back(temp->data);
            temp=temp->next;
            
        }
        
        int start=0;
        int end=el.size()-1;
        vector<int>ans;
        while(start<=end){
            if(start!=end){
                
                ans.push_back(el[start]);
                ans.push_back(el[end]);    
            }else{
                
                ans.push_back(el[start]);
            }
            
            start++;
            end--;
        }
        
        Node* ansnode=new Node(-1);
        temp=ansnode;
        for(int i=0;i<ans.size();i++){
           
            temp->next=new Node(ans[i]);
            temp=temp->next;
        }
        
        temp=ansnode->next;
        Node* temp2=head;
       
        // while(temp!=NULL){
        //     cout<<temp->data<<" ";
        //     temp=temp->next;
        // }
        // cout<<endl;
        while(temp2!=NULL){
            temp2->data=temp->data;
            temp2=temp2->next;
            temp=temp->next;
        }
    }
};

//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends
