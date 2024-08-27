//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        // 5 : 2
        // 4 : 2
        // 6 : 1
        // 1 6
        // 2 5 4
        vector<int>ans;
        unordered_map<int,int>mapping;
        for(auto i : arr){
            mapping[i]++;
        }
        // for(auto i : mapping){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        
        map<int,vector<int>>mapping2;
        for(auto i : mapping){
            mapping2[i.second].push_back(i.first);
        }
        map<int, vector<int>>::reverse_iterator i;
       for (i = mapping2.rbegin(); i != mapping2.rend(); i++) {
            vector<int>temp = i->second;
            sort(temp.begin(),temp.end());
            for(int k = 0; k<temp.size(); k++){
               for(int j =0; j<i->first;j++) ans.push_back(temp[k]);
            }
        }
        //reverse(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends
