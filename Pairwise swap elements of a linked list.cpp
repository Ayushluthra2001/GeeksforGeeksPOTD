//{ Driver Code Starts
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


// } Driver Code Ends
/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/
class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
        // The task is to complete this method
        vector<int>nodes;
        struct Node* temp=head;
        while(temp!=NULL){
            nodes.push_back(temp->data);
            temp=temp->next;
        }
        for(int i=0;i<nodes.size();i+=2){
            if(i+1<nodes.size())
            swap(nodes[i],nodes[i+1]);
        }
        for(auto i : nodes){
            cout<<i<<" ";
        }
        
        // struct Node* ans=new Node(-1);
        // temp=ans;
        // for(int i=0;i<nodes.size();i++){
        //     temp->next=new Node(nodes[i]);
        //     temp=temp->next;
        // }
        //temp=ans;
        
        // while(temp!=NULL){
        //     cout<<temp->data<<" ";
        //     temp=temp->next;
            
        // }
        // cout<<endl;
        // head=ans->next;
        return NULL;
    }
};

//{ Driver Code Starts.

void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

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
		map<Node*, int> mp;
		mp[head] = head->data;
		for (int i = 0; i<n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
			mp[tail] = tail->data;
		}
		struct Node *failure = new Node(-1);
		Solution ob;
		head = ob.pairWiseSwap(head);
		int flag = 0;
		struct Node *temp = head;
		while(temp){
		    if(mp[temp] != temp->data){
		        flag = 1;
		        break;
		    }
		    temp = temp->next;
		}
		if(flag)
		    printList(failure);
		else
		    printList(head);
	}
	return 0; 
}

// } Driver Code Ends
