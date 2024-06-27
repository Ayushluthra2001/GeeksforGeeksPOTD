//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    
    bool check(string temp){
        int start = 0;
        int end= temp.size()-1;
        
        while(start<=end){
            if(temp[start] != temp[end]) return false;
            start++,end--;
        }
        
        
        return true;
    }
    string pattern(vector<vector<int>> &arr) {
        // Code Here
        vector<string>rows;
        vector<string>cols;
        int n = arr.size();
        int m = arr[0].size();
        
        for(int i=0; i<n; i++){
            string temp="";
            for(int j=0;j<m;j++){
                if(arr[i][j]==0) temp+='0';
                else temp+='1';
            }
            rows.push_back(temp);
        }
        
        for(int i=0;i<m;i++){
            string temp="";
            
            
            for(int j=0;j<n;j++){
                if(arr[j][i]==0) temp+='0';
                else temp+='1';
            }
            cols.push_back(temp);
        }
        
        
        
        // for(auto i : rows) cout<<i<<" ";
        // cout<<endl;
        // for(auto i : cols) cout<<i<<" ";
        // cout<<endl;
        
      
        
        for(int i=0;i<rows.size();i++){
            
            if(check(rows[i])) {
                
                string  ch=to_string(i);
                string temp="";
                temp+=ch;
                temp+=" R";
                return temp;
            }
        }
        
         for(int i=0;i<cols.size();i++){
            
            if(check(cols[i])) {
                
                string ch = to_string(i);
                string temp="";
                temp+=ch;
                temp+=" C";
                return temp;
            }
        }
        
      
        return "-1";
       
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends
