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
    int minimumInteger(int N, vector<int> &A) {
        // code here
        long long int  sum=0;
        for(int i=0;i<A.size();i++){
            sum+=A[i];
        }
        int mini=INT_MAX;
        for(int i=0;i<N;i++){
            long long int x=(long long int)A[i]*(long long int) N;
            if(sum<=x){
                mini=min(mini,A[i]);
            }
        }
        return mini;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        int res = obj.minimumInteger(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
