//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    long long int MissingNo(vector<vector<int> >& matrix) {
        int n = matrix.size();
        long long int affected = -1;
        long long int unaffected = -1;
        long long int diago1 = 0;
        long long int diago2 = 0;
        bool d1aff = 0;
        bool d2aff = 0;
        for ( int i = 0; i<n; i++ ){
            long long int row = 0;
            long long int col = 0;
            bool caff = 0;
            bool raff = 0;
            for ( int j = 0; j<n; j++ ){
                col += matrix[j][i];
                row += matrix[i][j];
                
                if ( matrix[i][j] == 0) raff = 1;
                if ( matrix[j][i] == 0 ) caff = 1;
            }
            if ( affected == -1 ){
                if ( raff )
                    affected = row;
                    
                if ( caff )
                    affected = col;
            }
            
            if ( unaffected == -1 ){
                if ( !raff )
                    unaffected = row;
                if ( !caff )
                    unaffected = col;
            }
            
            if ( raff && affected != row )
                return -1;
            if ( caff && affected != col )  
                return -1;
            if ( !raff && unaffected != row )
                return -1;
            if ( !caff && unaffected != col)
                return -1;
                
            diago1 += matrix[i][i];
            diago2 += matrix[i][n-i-1];
            if ( matrix[i][i] == 0) 
                d1aff = 1;
            if ( matrix[i][n-1-i] == 0) 
                d2aff = 1;
            
        }
        if ( unaffected <= affected)
            return -1;
        if ( d1aff && affected != diago1 )
            return -1;
        if ( d2aff && affected != diago2 )
            return -1;
        if ( !d1aff && unaffected != diago1)
            return -1;
        if ( !d2aff && unaffected != diago2 )
            return -1;
            
        
        return unaffected-affected;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		long long int ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
