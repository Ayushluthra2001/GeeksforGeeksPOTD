//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    Node* reverse( Node* node){
        if(node==NULL) return NULL ;
        Node* curr=node;
        Node* next=NULL;
        Node* prev=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
    }
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        Node* Dummy=newNode(-1);
        Node* temp=Dummy;
        while(node1!=NULL && node2!=NULL){
            if(node1->data>=node2->data){
                temp->next=newNode(node2->data);
                node2=node2->next;
                temp=temp->next;
            }else{
                temp->next=newNode(node1->data);
                node1=node1->next;
                temp=temp->next;
            }
        }
        while(node1!=NULL){
            temp->next=newNode(node1->data);
            node1=node1->next;
            temp=temp->next;
        }
        while(node2!=NULL){
            temp->next=newNode(node2->data);
            node2=node2->next;
            temp=temp->next;
        }
        Node* final = Dummy->next;
        final =reverse(final);
        return final;
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends
