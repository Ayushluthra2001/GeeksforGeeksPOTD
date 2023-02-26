//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution
{
public:
    void reverseK(vector<int>& list, int k){
        int start=0;
        int end=k-1;
        while(start<=end){
            swap(list[start],list[end]);
            start++;
            end--;
        }
    }
    void reversek(vector<int>& list, int k){
        int start=k;
        int end=list.size()-1;
        while(start<=end){
            swap(list[start],list[end]);
            start++;
            end--;
        }
    }
    Node *reverse(Node *head, int k)
    {
        // code here
        vector<int>list;
        Node* temp=head;
        while(temp!=NULL){
            list.push_back(temp->data);
            temp=temp->next;
        }
        reverseK(list,k);
        reversek(list,k);
        Node* dummy=new Node(-1);
        temp=dummy;
        for(int i=0;i<list.size();i++){
            temp->next=new Node(list[i]);
            temp=temp->next;
        }
        return dummy->next;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends
