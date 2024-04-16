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
    int minimizeDifference(int n, int k, vector<int> &arr) {
        // code here

  vector<int> post_max(n);
        vector<int> post_min(n);
        
        post_min[n-1] = arr[n-1];
        post_max[n-1] = arr[n-1];
        
        for(int i = n-2; i>= 0; --i) {
            post_max[i] = max(arr[i] , post_max[i+1]);
            post_min[i] = min(arr[i] , post_min[i +1]);
        }
        
        int min_diff = post_max[k] - post_min[k];
        int p_min = arr[0];
        int p_max = arr[0];
        
        for( int i = 1; i<n-k; ++i) {
            int curr_min = max(p_max , post_max[i+k]) - min(p_min , post_min[i+k]);
            min_diff = min( min_diff , curr_min);
            p_max = max(arr[i] , p_max);
            p_min = min(arr[i] , p_min);
        }
        
        min_diff = min( min_diff , p_max - p_min);
        
        return min_diff;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
