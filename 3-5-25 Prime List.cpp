//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function Template for C++

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
    
    

class Solution {
  public:
  
  int findSmallest(int x, vector<int>& listOfPrimeNumbers) {
    int answer = -1; // default if no prime ≤ x exists
    int start = 0, end = listOfPrimeNumbers.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (listOfPrimeNumbers[mid] <= x) {
            answer = listOfPrimeNumbers[mid]; // potential candidate
            start = mid + 1; // try to find a closer larger one
        } else {
            end = mid - 1;
        }
    }

    return answer;
}


   int findLargest(int x, vector<int>& listOfPrimeNumbers) {
    int answer = -1;  // default if no prime ≥ x exists
    int start = 0, end = listOfPrimeNumbers.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (listOfPrimeNumbers[mid] >= x) {
            answer = listOfPrimeNumbers[mid]; // candidate found
            end = mid - 1;  // look for a smaller qualifying value
        } else {
            start = mid + 1;
        }
    }

    return answer;
}

  
    bool checkPrimeNumber(int x){
        if(x==0 || x==1) return false;
        for(int i = 2; i<=sqrt(x); i++){
            if(x % i==0) return false;
        }
        return true;    
    }
    Node *primeList(Node *head) {
        // code here
        vector<int>primeNumber(1e5,1);
        primeNumber[0]  = 0;
        primeNumber[1]  = 0;
        for(int i = 2; i<1e5; i++){
            if(primeNumber[i]==1){
                for(int j = i*2; j<1e5;j+=i){
                    primeNumber[j] = 0;
                }
            }
        }
        
        vector<int>listOfPrimeNumbers;
        for(int i = 0; i<primeNumber.size();i++){
            if(primeNumber[i]==1)
            listOfPrimeNumbers.push_back(i);
        }
        // for(auto i : listOfPrimeNumbers) cout<<i<<" ";
        // cout<<endl;
        // return head;
        Node* temp = head;
        while(temp != NULL){
            
            int curr = temp->val;
            
            if(checkPrimeNumber(curr)){
                temp = temp->next;
            }else{
                //int smallest = 0;
                
                int smallest = findSmallest(curr, listOfPrimeNumbers);
                int largest = findLargest(curr, listOfPrimeNumbers);
                
                if(abs(smallest - curr) <= abs(largest- curr)){
                    temp ->val = smallest;
                }else{
                    temp ->val = largest;
                }
                
                temp = temp->next;
            }
            
        }
        
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
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
