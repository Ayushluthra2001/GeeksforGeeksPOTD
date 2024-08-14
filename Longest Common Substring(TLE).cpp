//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    // int solve(string &str1,string &str2,int i, int j,int &maxi){
            
    //     if(i>=str1.length() || j>=str2.length()) return 0;
       
    //     if(str1[i] == str2[j]){
    //       return 1+ solve(str1,str2,i+1,j+1);
            
    //     }else{
    //         int notInclude1 = solve(str1,str2,i,j+1);
    //         int notInclude2 = solve(str1,str2,i+1,j);
            
    //         return max(notInclude1,notInclude2);
    //     }
        
    //     return -1; 
    // }
    int longestCommonSubstr(string str1, string str2) {
        // your code here
        // int maxi = 0;
        
        // return solve(str1,str2,0,0,maxi);
        int ans= 0;
        for(int i=0;i<str1.length();i++){
            for(int j=0;j<str2.length();j++){
                if(str1[i] == str2[j]){
                    int a= i;
                    int b= j;
                    int count = 0;
                    while(a<str1.length() && b<str2.length()){
                        if(str1[a] == str2[b]) a++,b++,count++;
                        else break;
                    }
                    ans = max(ans,count);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends
