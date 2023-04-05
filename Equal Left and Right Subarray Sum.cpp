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
    int equalSum(int N, vector<int> &A) {
        // code here
        // if(A.size()==1) return true;
        // vector<int>prefix;
        // vector<int>suffix;
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=A[i];
            // prefix.push_back(sum);
        }
        // sum=0;
        // for(int i=N-1;i>=0;i--){
        //     sum+=A[i];
        //     suffix.push_back(sum);
        // }
        // for(int i=0;i<N;i++){
        //     cout<<prefix[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<N;i++){
        //     cout<<suffix[i]<<" ";
        // }
        // cout<<endl;
        int l_sum=0;
        for(int i=0;i<N;i++){
            if(l_sum==sum-A[i]) return i+1;
            l_sum+=A[i];
            sum-=A[i];
        }
        return -1;
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
        int res = obj.equalSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
