//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
}
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<pair<int, int>> v; int m = 0;
        for(int i = 0; i < n; i++) {
            v.push_back({arr[i].dead, arr[i].profit});
            m = max(m, arr[i].dead);
        }
        sort(v.begin(), v.end(), cmp);
        vector<int> ans(2, 0), vis(m+1, 0);
        for(int i = 0; i < n; i++) {
            bool f = false;
            int j = v[i].first;
            while(j > 0) {
                if(!vis[j]) {
                    f = true, vis[j] = 1;
                    break;
                }
                j--;
            } 
            if(f) ans[0]++, ans[1] += v[i].second;
        }
        return ans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends
