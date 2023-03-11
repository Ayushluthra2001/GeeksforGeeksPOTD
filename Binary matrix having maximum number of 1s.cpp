//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        //code here
        int max_1s=0;
        int max_row=0;
        for(int i=0;i<mat.size();i++){
            int start=0,end=mat[0].size()-1;
            int first_pos=-1;
            while(start<=end){
                int mid=start+(end-start)/2;
                
                if(mat[i][mid]==1){
                    first_pos=mid;
                    end=mid-1;
                }else{
                    start=mid+1;
                }
            }
            // cout<<first_pos<<" "<<mat[0].size()-first_pos<<endl;
            if(first_pos!=-1 && max_1s<mat[0].size()-first_pos){
                max_1s=mat[0].size()-first_pos;
                max_row=i;
            }
        }
        return {max_row,max_1s};
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends
