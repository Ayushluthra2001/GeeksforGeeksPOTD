//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
        
        unordered_map<int,int>maxi;
        unordered_map<int,int>mini;
        
        for(int i = 0; i<arr.size(); i++){
            if(maxi.find(arr[i])!=maxi.end()){
                    maxi[arr[i]]= max(maxi[arr[i]] , i);
                
            }else{
                mini[arr[i]]= i;
                maxi[arr[i]]= i;
            }
        }
        
        int ans = 0;
        for(auto i :  maxi){
            ans = max(ans, i.second  - mini[i.first]);
        }
        
        return ans;
        
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

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
