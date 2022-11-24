//{ Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
    int find(long long x){
        int count=0;
        while(x>0){
            if(x%2==1) count++;
            x=x/2;
        }
        return count;
    }
public:
    
    long long count(long long x) {
        // Code Here
        int get=find(x);
        int count=0;
        for(long long i=1;i<x;i++){
            if(get==find(i)) count++;
        }
        return count;
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
