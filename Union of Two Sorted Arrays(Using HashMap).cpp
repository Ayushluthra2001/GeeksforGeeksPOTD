//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //  vector<int>ans;
        // int i=0,j=0;
        // while(i<n && j<m){
        //     if(arr1[i]>=arr2[j]){
        //         if(ans.size()==0){
        //             ans.push_back(arr2[j++]);
        //         }else if(ans[ans.size()-1]==arr2[j]){
        //             j++;
        //         }else{
        //             ans.push_back(arr2[j++]);
        //         }
        //     }else {
        //         if(ans.size()==0){
        //             ans.push_back(arr1[i++]);
        //         }else if(ans[ans.size()-1]==arr1[i]){
        //             i++;
        //         }else{
        //             ans.push_back(arr1[i++]);
        //         }
        //     }
        // }
        // while(i<n){
        //     if(ans.size()!=0 && ans[ans.size()-1]==arr1[i]) i++;
        //     else ans.push_back(arr1[i++]);
        // }
        // while(j<m){
        //     if(ans.size() !=0 && ans[ans.size()-1]==arr2[j]) j++;
        //     else ans.push_back(arr2[j++]);
        // }
        // return ans;
       
        unordered_map<int,int>mapping;
        for(int i=0;i<n;i++){
            mapping[arr1[i]]++;
        }
        for(int i=0;i<m;i++){
            mapping[arr2[i]]++;
        }
        vector<int>ans;
        for(auto i : mapping){
            ans.push_back(i.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
 
        



        

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
