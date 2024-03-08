//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    vector<int> cnt(26, 0);
    for(int i=0; i<s.length(); i++){
        cnt[s[i]-'a']++;
    }
    vector<pair<int, int>> freq(3, {0, 0});
    int k = 0;
    sort(cnt.begin(), cnt.end());
    for(int i=0; i<26; i++){
        if(cnt[i]==0) continue;
        else {
            if(freq[k].first == 0){
                    freq[k].first = cnt[i];
                    freq[k].second = 1;
                } else if(freq[k].first == cnt[i]){
                    freq[k].second++;
                } else {
                    k++;
                    if(k==2) return false;
                    freq[k].first = cnt[i];
                    freq[k].second = 1;
                }
        }
    }
        if(k==0 || freq[0].first == 1 && freq[0].second == 1) return true;
        if(freq[1].first-freq[0].first == 1 && freq[1].second == 1) return true;
        return false;
	   
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends
