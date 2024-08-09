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
    void giveMeDataBrother(Node* head , vector<int>&temp){
        
        Node* t = head;
        while(t!=NULL){
            temp.push_back(t->data);
            t = t->next;
        }
        
        return ;
    }
    vector<int> broGiveMeRotatedArray(vector<int>& data ,int k){
        vector<int>temp = data;
        
        for(int i=0;i<data.size();i++){
            temp[(i-k + data.size())%data.size()] = data[i];
        }
        
        return temp;
        
    }
    Node* brotherGiveMeLinkedList(vector<int>&data){
        Node* ans = new Node(-1);
        Node* temp = ans;
        
        for(int i=0;i<data.size();i++){
            temp ->next = new Node(data[i]);
            temp = temp->next;
        }
        
        return ans->next;
    }
    Node* rotate(Node* head, int k) {
        // Your code here
        vector<int>data; 
        giveMeDataBrother(head,data);
        
        data =  broGiveMeRotatedArray(data,k);
        
        return brotherGiveMeLinkedList(data);
        
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
