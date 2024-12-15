//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
       int i = 0 ;
       int j = 0;
       int count =0;
       while(i < a.size() && j < b.size() && count < k-1){
           
           if(a[i] >= b[j]){
               count++;
               j++;
               
           }else i++,count++;
       }
      
         if(i < a.size() && j<b.size()) return min(a[i],b[j]);
         
          if (i < a.size()) return a[i + (k - count - 1)];
    if (j < b.size()) return b[j + (k - count - 1)];
         
         return 0;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends
