//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int n, int k, vector<int> &a) {
        if(n%k!=0)return false;
        map<int,int>m;
        for(int i:a){
            m[i]+=1;
        }
        while(!m.empty()){
            int s = m.begin()->first;
            int l = k;
            while(l--){
                if(!m[s])return false;
                else{
                    m[s]--;
                    if(m[s]==0)m.erase(s);
                }
                s++;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends
