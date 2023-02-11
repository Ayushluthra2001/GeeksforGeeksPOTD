//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
   int getMinimumDays(int n, string s, vector<int> &p) {
        // code here
        int i = 0 , j = 0, ans = INT_MIN;
        while(i < n-1 && j < n){
            if(s[i] == s[i+1] && s[i] != '?'){
                while(s[i+1] != '?' && s[i] != '?'){
                    ans = max(ans, j);
                    s[p[j]] = '?';
                    j++;
                }
            }
            i++;
        }
        return ans == INT_MIN ? 0 : ans+1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        string S;cin>>S;
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        int res = obj.getMinimumDays(N,S, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
