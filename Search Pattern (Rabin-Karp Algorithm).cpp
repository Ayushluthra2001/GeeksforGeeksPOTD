//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            //code here.
            vector<int>ans;
            //cout<<text.length() << " "<<pattern.length()<<endl; 
            for(int i=0;i<=text.length()-pattern.length();i++){
                //cout<<i<< " ";
                if(pattern[0]==text[i]){
                    //cout<<i<<" ";
                    int j=0;
                    int k=i;
                    while(j<pattern.length() && k<text.length() &&pattern[j]==text[k])k++,j++;
                    if(j==pattern.length()) ans.push_back(i+1);
                    
                }
               // cout<<endl;
                
        
            }
    return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
