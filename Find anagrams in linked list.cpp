//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {

        // code here

        int n=s.size();

        Node *st=head,*e=head;

        unordered_map<char,int>mp1,mp2;

        for(int i=0;i<n;i++){

            mp1[s[i]]++;

        }

        vector<Node*>ans;

        while(head){

            st=head;

            for(int i=0;i<n;i++){

                if(head){

                mp2[head->data]++;

                e=head;

                head=head->next;

                }

                else break;

            }

            

            if(mp2==mp1){

                e->next=NULL;

                ans.push_back(st);

                mp2.clear();

            }

            else{

                head=st->next;

                mp2.clear();

            }

        }

        return ans;

    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends
