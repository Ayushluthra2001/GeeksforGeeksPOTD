//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> v, int k) {
        if(v.size()%2==1 || accumulate(v.begin(), v.end(), 0)%k!=0) return false;
        unordered_map<int, int> m;
        for(int i=0; i<v.size(); i++){
            v[i] = v[i]%k;
            m[v[i]]++;
        }
        for(int i=0; i<v.size(); i++) 
        if(m[v[i]])
        {
            if(v[i])
            {
                m[v[i]]--;
                if(!(m.find(k-v[i])!=m.end() && m[k-v[i]])) return false;
                else m[k-v[i]]--;
            }
            else
            {
                m[0]--;
                if(!(m.find(0)!=m.end() && m[0])) return false;
                else m[0]--;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends
