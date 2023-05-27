//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
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
    Node * reverse(Node *h){
        Node *c=h;
        Node *n=NULL;
        Node *f=h;
        while(c){
            f=c->next;
            c->next=n;
            n=c;
            c=f;
        }
        return n;
    }
    struct Node* modifyTheList(struct Node *head)
    {
        //add code here.
        if(head==NULL or head->next==NULL) return head;
        Node * slow=head;
        Node *fast=head;
        Node *l;
        while(fast and fast->next){
            l=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
     
        l->next=NULL;
    Node *p=reverse(slow);

    Node *f=head;
    Node *k=p;
    while(f and k){
        int fi=f->data;
        int se=k->data;
        f->data=se-fi;
        k->data=fi;
        k=k->next;
        f=f->next;
    }
  
    p=reverse(p);
    l->next=p;
        return head;
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends
