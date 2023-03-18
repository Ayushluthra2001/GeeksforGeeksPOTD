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
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        // code here    
        vector<int>prefix;
        vector<int>sufix(N,0);
        unordered_map<int,int>mapping,mapping2;
        for(int i=0;i<N;i++){
            prefix.push_back(mapping.size());
            mapping[A[i]]++;
            
        }
        for(int i=N-1;i>=0;i--){
            sufix[i]=mapping2.size();
            mapping2[A[i]]++;
        }
        vector<int>ans(N,0);
        for(int i=0;i<N;i++){
            // cout<<prefix[i]<<" "<<sufix[i]<<" "<<endl;
            ans[i]=prefix[i]-sufix[i];
        
        }
        return ans;
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
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends
