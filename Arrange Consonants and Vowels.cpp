//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

void printlist(Node *head)
{
	if (head==NULL)return;
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void append(struct Node** headRef, char data)
{
	struct Node* new_node = new Node(data);
	struct Node *last = *headRef;

	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/

class Solution
{
    public:
    // task is to complete this function
    // function should return head to the list after making 
    // necessary arrangements
    bool check(Node* temp){
        if(temp->data=='a' || temp->data=='e' || temp->data=='i' || temp->data=='o' || temp->data=='u') return true;
        return false;
        
    }
    struct Node* arrangeCV(Node *head)
    {
       //Code here
       vector<char>vowel,consonant;
       Node* temp=head;
       while(temp!=NULL){
           if(check(temp)) vowel.push_back(temp->data);
           else consonant.push_back(temp->data);
           temp=temp->next;
       }
       Node* dummy =new Node(-1);
       temp=dummy;
       for(int i=0;i<vowel.size();i++){
           temp->next=new Node(vowel[i]);
           temp=temp->next;
       }
       for(int i=0;i<consonant.size();i++){
           temp->next=new Node(consonant[i]);
           temp=temp->next;
       }
       return dummy->next;
    }
};


//{ Driver Code Starts.

// task is to complete this function
int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        char tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
	return 0;
}


// } Driver Code Ends
