//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
     pair<long long,long long> findmedianpair2(vector<long long> &a,int start,int end)
    {
        int low = start;
        int high = end-1;
        long long prev=0;
        if(start!=0) prev = a[start-1];
        long long mini = 1e10;
        long long ret1;
        long long ret2;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            long long first = a[mid]-prev;
            long long second = a[end-1]-a[mid];
            if(first>second)
            {
                if((first-second)<mini)
                {
                    mini = first-second;
                    ret1 = second;
                    ret2 = first;
                }
                high = mid-1;
            }
            else if(first==second)
            {
                return {first,second};
            }
            else
            {
                if((second-first)<mini)
                {
                    mini = second-first;
                    ret2 = second;
                    ret1 = first;
                }
                low = mid+1;
            }
        }
        return {ret1,ret2};
    }
    long long minDifference(int n, vector<int> &a) {
        vector<long long> prefixsum(n,0);
        for(int i=0;i<n;i++)
        {
            prefixsum[i]=a[i];
            if(i>0) prefixsum[i]+=prefixsum[i-1];
        }
        long long ans=1e15;
        for(int i=2;i<=n-2;i++)
        {
            auto p = findmedianpair2(prefixsum,0,i);
            auto q = findmedianpair2(prefixsum,i,n);
            long long mini = min(p.first,q.first);
            long long maxi = max(p.second,q.second);
            ans = min(ans,(maxi-mini));
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        long long ans = ob.minDifference(N, A);
        cout<<ans<<endl;
    }
    return 0;
} 
// } Driver Code Ends
