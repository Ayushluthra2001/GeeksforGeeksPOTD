//{ Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{

    private: 
        long long nCr(long long n, long long r){
            if(r > n){
                return 0;
            }
            long long res = 1;
            for(int i = 0; i < r; i++){
                res *= (n - i);
                res /= (i + 1);
            }
            return res;
        }
    public:
    
        long long count(long long x) {
            if(x == 1){
                return 0;
            }
            long long num = x;
            long long cnt = 0;
            long long i = 0;
            long long ans = 0;
            while(num != 0){
                if((num & 1) == 1){
                    cnt++;
                    ans += nCr(i, cnt);
                }
                i++;
                num >>= 1;
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main() {
    
	int t;
	cin >> t;
	while (t-- > 0) {
	    long long x; cin >> x;
	    Solution ob;
	    cout << ob.count(x) << '\n';
	}
	return 0;
}
// } Driver Code Ends
