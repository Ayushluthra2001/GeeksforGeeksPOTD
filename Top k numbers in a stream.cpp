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

//{ Driver Code Starts



// } Driver Code Ends

class Solution {
   public:
    vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
        vector<int> top(K + 1,0);
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        for (int i = 0; i < N; i++) {
            mp[arr[i]]++;
            top[K] = arr[i];
            auto it = find(top.begin(), top.end() - 1, arr[i]);
            int index = it - top.begin() - 1;
            for (int j = index ; j >= 0; --j) {
                if (mp[top[j]] < mp[top[j + 1]])
                    swap(top[j], top[j + 1]);
                else if ((mp[top[j]] == mp[top[j + 1]]) && (top[j] > top[j+1]))
                    swap(top[j], top[j + 1]);
                else
                    break;
            }
            vector<int>temp;
            for (int i = 0; i < K && top[i] != 0; ++i)
                temp.push_back(top[i]);
            ans.push_back(temp);
        }
        return ans;
    }
};


//{ Driver Code Starts.



// } Driver Code Ends


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> a(N);
        Array::input(a,N);
        
        Solution obj;
        vector<vector<int>> res = obj.kTop(a, N, K);
        
        for(auto it:res)
            Array::print(it);
        
    }
}

// } Driver Code Ends
