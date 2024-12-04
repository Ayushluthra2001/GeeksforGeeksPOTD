//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int countZero = 0, countOne = 0, countTwo = 0;
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] == 0 ) countZero++;
            else if(arr[i] == 1) countOne++;
            else countTwo++;
        }
        
        for(int i = 0; i< arr.size(); i++){
            if(countZero >0 ) arr[i] = 0 , countZero--;
            else if(countOne > 0) arr[i] = 1 , countOne--;
            else arr[i] = 2;
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
