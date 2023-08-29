//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        vector<int>nodes;
        Node* temp=head;
        while(temp!=NULL){
            nodes.push_back(temp->data);
            temp=temp->next;
        }
        
         reverse(nodes.begin(),nodes.end());
         vector<int>ans;
         int maxi=nodes[0];
         ans.push_back(nodes[0]);
        for(int i=1;i<nodes.size();i++){
            if(nodes[i]>=maxi){
                maxi=nodes[i];
                ans.push_back(nodes[i]);
            }
        }
        
        reverse(ans.begin(),ans.end());
        Node* dummy=new Node(-1);
        Node* temp2=dummy;
        for(int i=0;i<ans.size();i++){
            temp2->next=new Node(ans[i]);
            temp2=temp2->next;
        }
        return dummy->next;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends
