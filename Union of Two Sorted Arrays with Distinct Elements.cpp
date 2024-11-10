//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        vector<int>result;
        
        int i = 0 , j =0;
        int n = a.size();
        int m = b.size();
        
        while(i < n && j < m){
            if(a[i] >= b[j]){
                if(result.size() >=1 && b[j]==result[result.size()-1]){
                    j++;
                }else result.push_back(b[j++]);
            }else {
                if(result.size()>=1 && a[i]==result[result.size()-1]){
                    i++;
                }else result.push_back(a[i++]);
            }
        }
        
        while(i < n){
            if(a[i]==result[result.size()-1]){
                i++;
            }else result.push_back(a[i++]);
        }
         while(j < m){
            if(b[j]==result[result.size()-1]){
                j++;
            }else result.push_back(b[j++]);
        }
        
        return result ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
