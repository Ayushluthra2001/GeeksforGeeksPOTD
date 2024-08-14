//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

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

class Solution {
    Node* reverse(Node* head){
     
        Node* curr    = head;
        Node* forward = head;
        Node* prev    = NULL;
        
        
        while(curr != NULL){
            
            forward = curr ->next; 
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        
        return prev;
    }
  public:
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
       
       head = reverse(head);
        Node* temp = head;
        int carry = 1;
        while(temp!=NULL){
            
            int sum =0;
            sum = carry + temp->data;
            
           
           
                temp->data = sum%10;
                carry = sum/10;
                temp = temp->next;    
         
            
            
        }
       
      
        if(carry > 0){
            temp = head;
            while(temp->next!=NULL){
                temp = temp ->next;
            }
            temp->next = new Node(carry);
            temp = temp ->next;
            
        }
        
        head = reverse(head);
        
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends
