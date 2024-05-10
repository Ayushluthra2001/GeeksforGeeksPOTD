//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
vector<vector<int>> ans;
void solve(vector<int> &arr, int k, int ind, vector<int> &temp)
{
    if (k == 0)
    {
        ans.push_back(temp);
        return;
    }
    for (int i = ind; i < arr.size(); i++)
    {
        if (arr[i] > k)
            break;
        if (i > ind && arr[i] == arr[i - 1])
            continue;
        temp.push_back(arr[i]);
        solve(arr, k - arr[i], i + 1, temp);
        temp.pop_back();
    }
}
vector<vector<int>> CombinationSum2(vector<int> arr, int n, int k)
{
    vector<int> temp;
    sort(arr.begin(), arr.end());
    solve(arr, k, 0, temp);
    return ans;
}
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
