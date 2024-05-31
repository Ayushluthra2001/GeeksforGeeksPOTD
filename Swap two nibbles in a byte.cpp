//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int swapNibbles(int n) {
        // code here
        vector<int>bits;
        int i=0;
        while(n>0 || i<8){
            if(n>0){
                if(n%2==0)
                bits.push_back(0);
                else bits.push_back(1);
                n=n/2;
            }else bits.push_back(0);
            i++;
        }
        reverse(bits.begin(),bits.end());
        //for(auto i : bits) cout<<i<<" ";
        //cout<<endl;
         i=0;
        int j=4;
        while(j<8){
            swap(bits[i],bits[j]);
            j++,i++;
        }
        //for(auto i : bits) cout<<i<<" ";
        int x=0;
        int p=0;
        for(int i=bits.size()-1;i>=0;i--){
            x+=bits[i]*pow(2,p);
            p++;
        }
        return x;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends
