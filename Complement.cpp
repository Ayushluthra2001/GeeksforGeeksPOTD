//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findRange(string str, int n) {
        // code here
        
        int i=0;
        int j=0;
        unordered_map<char ,int> mp;
        int maxSub = 0;
        vector<int> ans = {-1};
        int temp = 0;
        
        while(j < n){
            
            mp[str[j]]++;
            
            if(mp['0'] >= mp['1']){
                
                temp = mp['0'] - mp['1'];
                if(temp > maxSub){
                    maxSub = temp;
                    ans = {i+1, j+1};
                }
                j++;
                
            }else{
                
                while(mp['0'] < mp['1']){
                    mp[str[i]]--;
                    if(mp[str[i]] == 0) mp.erase(str[i]);
                    i++;
                }
                j++;
            }
        }
        if(ans[0] == -1) return {-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends
