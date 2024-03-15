//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
/* Function to print linked list */


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



// } Driver Code Ends

/*
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

class Solution
{
    public:
    // your task is to complete this function
    void sort(Node **head)
    {
         Node *last=NULL,*ptr=*head,*pre,*result=NULL;
         if(ptr->next==NULL || ptr->next->next==NULL) return;
         
        while(ptr && ptr->next){
            Node *temp=ptr->next;
            ptr->next=ptr->next->next;
            if(last==NULL){
                last=temp;
                last->next=NULL;
            }else{
                temp->next=last;
                last=temp;
            }
            if(ptr!=NULL){
                pre=ptr;
            ptr=ptr->next;
            }
         }
     ptr=*head;
     if(ptr->data >last->data){
         *head=result=last;
         last=last->next;
     }else{
         *head=result=ptr;
         ptr=ptr->next;
     }
     
     while(ptr && last){
          if(ptr->data>last->data){
             if(last->next==NULL){
                 last->next=ptr;
                 result->next=last;
                 break;
             }else{
                 result->next=last;
                 last=last->next;
             }
          }else{
              if(ptr->next==NULL){
                  ptr->next=last;
                  result->next=ptr;
                  break;
              }else{
                  result->next=ptr;
                  ptr=ptr->next;
              }
          }
          result=result->next;
     }
     
    }
};

//{ Driver Code Starts.
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    Solution ob;
	    ob.sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends
