//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range2, int q, vector<int>queries){
        //Write your code here
        int maxi=0;
        int mini=INT_MAX;
        vector<int>ans;
        vector<vector<int>>range;
        for(int i=0;i<range2.size();i++){
            if(range.size()==0){
                range.push_back({range2[i][0],range2[i][1]});
            }else{
                if(range[range.size()-1][1]>=range2[i][0]){
                    int mini=INT_MAX;
                    int maxi=INT_MIN;
                    mini=min(range2[i][0],range[range.size()-1][0]);
                    maxi=max(range2[i][1],range[range.size()-1][1]);
                    range[range.size()-1]={mini,maxi};
                    
                }else{
                    range.push_back({range2[i][0],range2[i][1]});
                }
            }
        }
        
        // for(auto i : range){
        //     cout<<i[0]<<" "<<i[1]<<endl;
            
        // }
        // cout<<endl;
        set<int>s;
        for(int i=0;i<range.size();i++){
            for(int j=range[i][0];j<=range[i][1];j++){
                s.insert(j);
            }
            
        }
      vector<int>ranges(s.begin(),s.end());
        for(int i=mini;i<=maxi;i++){
            ranges.push_back(i);
        }
        sort(ranges.begin(),ranges.end());
        // for(auto i : ranges){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        for(int i=0;i<queries.size();i++){
            if(queries[i]>ranges.size()){
                ans.push_back(-1);
            }else{
                ans.push_back(ranges[queries[i]-1]);
            }
        }
        return ans;
    } 
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends
