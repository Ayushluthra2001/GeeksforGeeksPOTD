//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        vector<int>postive;
        vector<int>negative;
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] >= 0 )postive.push_back(arr[i]);
            else negative.push_back(arr[i]);
            
        }
        int a = 0 , b = 0;
        int i = 0;
        while(i < arr.size()){
            if(a < postive.size() && b < negative.size()){
                arr[i] = postive[a++];
                arr[i+1] = negative[b++];
                i+=2;
            }else if( a < postive.size() ) arr[i++] = postive[a++];
            else arr[i++] = negative[b++];
        }
        return ;
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
