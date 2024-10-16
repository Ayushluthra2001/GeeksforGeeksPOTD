//{ Driver Code Starts
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


// } Driver Code Ends
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
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        // Your code here
        vector<Node* >ans;
        
        
        struct Node* temp1 = new Node(-1);
        struct Node* temp2 = new Node(-1);
        struct Node* temp3 = temp1;
        struct Node* temp4 = temp2;
        
        Node* temp5 = head;
        while(temp5 != NULL){
            temp3->next = new Node(temp5->data);
            temp5 = temp5->next;
            temp3=temp3->next;
            
            if(temp5!=NULL){
                temp4->next = new Node(temp5->data);
                temp5 = temp5->next;
                temp4 = temp4->next;
            }
        }
        ans.push_back(temp1->next);
        ans.push_back(temp2->next);
        return ans;
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

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

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends
