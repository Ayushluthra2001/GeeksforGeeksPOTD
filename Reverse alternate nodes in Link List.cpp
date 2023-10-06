//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/#include<bits/stdc++.h>
class Solution
{
    public:
    void rearrange(struct Node *odd)
    {
        //add code here
        vector<int>nodesalter;
        vector<int>restnodes;
        vector<int>nodes;
        struct Node* temp=odd;
        while(temp!=NULL){
            nodes.push_back(temp->data);
            temp=temp->next;
        }
        for(int i=0;i<nodes.size();i++){
            if(i%2==0){
                restnodes.push_back(nodes[i]);
            }else {
                nodesalter.push_back(nodes[i]);
            }
        }
        nodes.clear();
        // for(auto i : nodesalter){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        for(auto i : restnodes){
            nodes.push_back(i);
        }
        reverse(nodesalter.begin(),nodesalter.end());
        for(auto i : nodesalter)
            nodes.push_back(i);
        // for(auto i : nodes){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        struct Node* ans=new Node(-1);
        temp=ans;
    
        for(int i=0;i<nodes.size();i++){
            temp->next=new Node(nodes[i]);
            temp=temp->next;
        }
        temp=ans->next;
        struct Node* temp2=odd;
        while(temp!=NULL){
            temp2->data=temp->data;
            temp=temp->next;
            temp2=temp2->next;
        }
        
        
        
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends
