//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
   vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        //Write your code here
        vector<int>temp=queries;
        sort(temp.begin(),temp.end());
        sort(range.begin(),range.end());
        unordered_map<int,int>ump;
        int ri=0,j=0;
        int prev=-1;
        for(int i=0 ; i<range.size() ; i++){
            if(prev>=0 && range[prev][1]>=range[i][0]){
                if(range[prev][1]<range[i][1]){
                    range[i][0]=range[prev][1]+1;
                }
                else{
                    // i++;
                    continue;
                }
            }
            prev=i;
            int li=ri+1;
            ri=range[i][1]-range[i][0]+li;
            while(j<temp.size() && (li<=temp[j] &&ri>=temp[j])){
                int t=range[i][0]+temp[j]-li;
                ump[temp[j]]=t;
                j++;
            }
        }
        vector<int>res;
        for(int i=0 ; i<temp.size() ; i++){
            if(ump.find(queries[i])!=ump.end()){
                res.push_back(ump[queries[i]]);
            }
            else{
                res.push_back(-1);
            }
        }
        return res;
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
