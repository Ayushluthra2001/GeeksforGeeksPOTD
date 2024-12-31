//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
       int N = arr.size()-1;
       map<int,int>mapping;
      for(int i=0;i<N;i++){
          mapping[arr[i]]++;
      }
      int longest=0;
      int prev=-1;
      int count=0;
      for(auto i : mapping){
          if(prev==-1){
              prev=i.first;
              
              count++;
              longest=max(longest,count);
          }else if(abs(prev-i.first)==1){
              prev=i.first;
              
              count++;
              longest=max(longest,count);
             
          }else{
              prev=i.first;
              longest=max(longest,count);
              count=1;
          }
         
      }
       
       return longest;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
