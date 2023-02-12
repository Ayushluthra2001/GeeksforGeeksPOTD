//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/
class Solution{
public:
    bool isPrime(int x ){
        if(x<=1) return false;
        for(int i=2;i*i<=x;i++){
            if(x%i==0){
                return false;
            }
        }
        return true;
    }
    Node *primeList(Node *head){
        Node* temp=head;
        while(temp!=NULL){
            int num=temp->val;
            int l=num;
            int r=num;
            while(l>=0 || r<num*num){
                if(isPrime(l)){
                    temp->val=l;
                    break;
                }
                if(isPrime(r)){
                    temp->val=r;
                    break;
                }
                l--;
                r++;
            }
            temp=temp->next;
        }
        return head;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
