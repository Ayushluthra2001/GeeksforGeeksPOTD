//{ Driver Code Starts
//

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

// } Driver Code Ends
/*
structure of the node of the list is as
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
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        // Code here
    // one node case
        if(head->next==NULL){
            if(data>=head->data){
                head->next=new Node(data);
                return head;
            }else{
                int store=head->data;
                head->data=data;
                head->next=new Node(store);
                return head;
            }
        }
        struct Node* temp=head;
        // inserting data at start 
        if(data<=head->data){
            Node* dummy=new Node( data);
            dummy->next=head;
            return dummy;
        }
        struct Node* ans=new Node(-1);
        Node* temp2=ans;
        while(temp!=NULL && temp->data<=data){
            temp2->next=new Node(temp->data);
            temp2=temp2->next;
            temp=temp->next;
        }
        if(temp==NULL) temp2->next=new Node(data);
        else {
            
            temp2->next=new Node(data);
            
            temp2->next->next=temp;
            
            
        }
        return ans->next;
    }
};


//{ Driver Code Starts.
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
        
		int data;
		cin>>data;
		
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		
		int k;
		cin>>k;
		Solution obj;
		head = obj.sortedInsert(head,k);
		printList(head); 
	}
	return 0; 
} 

// } Driver Code Ends
