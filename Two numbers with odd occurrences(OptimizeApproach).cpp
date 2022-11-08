//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        int XOR = 0;
        for(int i = 0; i < N; i++)
        {
            XOR ^= Arr[i];
        }
        int index = 0;
        //Finding the first Set Bit
        while(XOR)
        {
            if(XOR & 1)
            {
                break;
            }
            index++;
            XOR = XOR>>1;
        }
        int XOR1 = 0, XOR2 = 0;
        for(int i = 0; i < N; i++)
        {
            if(Arr[i] & (1<<index))
            {
                XOR1 ^= Arr[i];
            }
            else
            {
                XOR2 ^= Arr[i];
            }
        }
        return {max(XOR1, XOR2), min(XOR1, XOR2)};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
