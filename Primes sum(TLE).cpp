//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    bool check(int num){
        for(int i=2;i<num;i++){
            if(num%i==0) return false;
        }
        return true;
    }
    string isSumOfTwo(int N){
        // code here
        int start=2;
        int end=N;
        while(start<=end){
            if(start+end==N && check(start) && check(end)) return "Yes";
            else if(start+end>N) end--;
            else start++;
        }
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends
