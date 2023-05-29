//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        // code here
        vector<string>ans;
        map<string,vector<string>>mapping;
        for(int i=0;i<N;i++){
            string pat="";
            for(int j=0;j<Dictionary[i].length();j++){
                if(Dictionary[i][j]>='A' && Dictionary[i][j]<='Z'){
                    pat+=Dictionary[i][j];
                }
                
            }
            mapping[pat].push_back(Dictionary[i]);
        }
       for(auto i : mapping){
           int j=0;
           bool flag=true;
           int k=0;
           string temp=i.first;
           while(j<Pattern.length() && k<i.first.length()){
               if(Pattern[j]!=temp[k]) {
                   flag=false;
                   break;
               }else{
                   j++;
                   k++;
               }
           }
           
           if(flag && j==Pattern.length()){
               for(auto j : i.second){
                   ans.push_back(j);
               }
           }
       }
        if(ans.size()==0) return {"-1"};
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
