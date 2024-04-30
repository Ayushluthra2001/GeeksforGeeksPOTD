//{ Driver Code Starts
// driver

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

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverse(struct Node* dummy ){
        
        Node* prev=NULL;
        Node* curr=dummy;
        Node* forward=dummy;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* data1, struct Node* data2)
    {
        // code here
        // vector<int>data1,data2;
        // Node* temp=num1;
        // while(temp!=NULL){
        //     data1.push_back(temp->data);
        //     temp=temp->next;
        // }
        // temp=num2;
        // while(temp!=NULL){
        //     data2.push_back(temp->data);
        //     temp=temp->next;
        // }
        data1=reverse(data1);
        data2=reverse(data2);
     //   reverse(data2.begin(),data2.end());
        //vector<int>ans;
        Node* i=data1;
        Node* j=data2;
        int carry=0;
        Node* dummy = new Node(-1);
        Node* temp=dummy;
       
        while(i!=NULL || j!=NULL || carry>0){
            int sum=0;
            sum+=carry;
            if(i!=NULL) {
                sum+=i->data;
                i=i->next;
            }
            if(j!=NULL) {
                sum+=j->data;
                j=j->next;
                
            }
            int s=sum%10;
            carry=sum/10;
            
            temp->next= new Node(s);
            temp=temp->next;
                
            
            
        }
         
        dummy =dummy->next;
        temp=dummy;
        
        
        dummy=reverse(dummy);
        while(dummy!=NULL){
            if(dummy->data==0) dummy=dummy->next;
            else break;
        }
        if(dummy==NULL) return new Node(0);
        
        return dummy;
        // Node* temp=data1;
        // while(temp!=NULL){
        //     cout<<temp->data<<" ";
        //     temp=temp->next;
        // }
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends
