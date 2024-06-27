//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isToeplitz(vector<vector<int>> &mat);

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        bool b = isToeplitz(a);

        if (b == true)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



bool isToeplitz(vector<vector<int>>& mat) {
    // code here
    int n = mat.size();
    int m = mat[0].size();
    //cout<<n<<" "<<m<<endl;
   
    
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    //return true;
    for(int j=m-1;j>=0;j--){
        int a=j;
        int b=0;
        int prev=-1;
        while(a<m && b<n){
            //cout<<a<<" "<<b<<" "<<mat[b][a]<<endl;
            //cout<<prev<<" "<<mat[b][a]<<endl;
            if(prev==-1){
               prev=mat[b][a];
                
           }else if(prev!=-1 && prev!=mat[b][a]) return false;
        //   cout<<b<<a<<" ";
            a++;
            b++;
           
        }
         //cout<<endl;
        
        
        
    
    }
    for(int j=1;j<n;j++){
        int a=j;
        int b=0;
        int prev=-1;
        while(a<n && b<m){
            if(prev==-1){
                prev=mat[a][b];
            }else if(prev!=-1 && prev!=mat[a][b]) return false;
        
            a++;
            b++;
        }
    }

    return true;
}
