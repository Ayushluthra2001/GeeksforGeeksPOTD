
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        priority_queue<long long ,vector<long long>,greater<long long>> q;
        for(int i=0;i<n;i++){
            q.push(arr[i]);
        }
        long long mini=0;
        while(q.size()>1){
                
                long long sum=q.top();
                q.pop();
                sum+=q.top();

                q.pop();
                
                mini+=sum;
               
                q.push(sum);
                
            }
        
        return mini;
    }
};



int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
