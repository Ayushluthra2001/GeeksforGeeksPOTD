//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        
        vector<int>ans;
        unordered_map<int,int>mapping;
        for(auto i : nums) {
            mapping[i]++;
            if(mapping[i] > nums.size()/3 && find(ans.begin(),ans.end(),i) == ans.end()){
                ans.push_back(i);
                mapping.erase(i);
            }
        }
       
        
        
        return ans.size()==0 ? vector<int>{-1}  : ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
