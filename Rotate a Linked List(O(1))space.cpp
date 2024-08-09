//{ Driver Code Starts
// Initial Template for C++
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
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    // Function to rotate a linked list.
    int giveMeSizeOfLinkedListBrother(Node* head){
        
        int count = 0;
        Node* temp = head;
        
        while( temp != NULL) {
            count++;
            temp = temp ->next;
        }
        
        return count;
    }
    Node* rotate(Node* head, int k) {
        // Your code here
       
        Node* temp = head;
        Node* start = head;
        int size = giveMeSizeOfLinkedListBrother(head);
        while(temp->next != NULL) temp = temp->next;
        temp ->next = start;
        
        temp = head;
        k = k % size;
        k = k + size;
        while(k--) temp = temp->next;
        
        start = temp;
        
        while(size>1){
           
            temp = temp->next;
            size --;
            
        }
       
       
        temp->next = NULL;
         
        
        
        return start;
    
        
        
        return start;
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

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends
