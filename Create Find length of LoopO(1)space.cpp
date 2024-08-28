//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void loopHere(Node *head, Node *tail, int position) {
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
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
    private : 
    struct Node* findLoop(struct Node* head){
        struct Node* temp = head;
        struct Node* next = head->next;
        while(next != NULL && temp!=next){
            temp = temp ->next;
            next = next ->next;
            if(next!=NULL)
            next = next->next;
        }
        if(next==NULL) return NULL;
        return temp;
    
    }
    int findLength(Node* WGL){
        struct Node* temp = WGL->next;
        int count = 1;
        while(temp != WGL){
            count++;
            temp = temp->next;
        }
        
        return count;
    }
  public:
  
  
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(struct Node *head) {
        // Code here
        
        struct Node* loopExist = findLoop(head);
        
        if(loopExist == NULL) return 0;
        
        int length = findLength(loopExist);
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
        int k;
        cin >> k;
        cin.ignore();
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        loopHere(head, tail, k);

        Solution ob;
        cout << ob.countNodesinLoop(head) << endl;
    }
    return 0;
}

// } Driver Code Ends
