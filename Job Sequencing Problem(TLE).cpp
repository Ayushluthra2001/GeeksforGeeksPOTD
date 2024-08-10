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
class Solution 
{
public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<vector<int>> temp;
        vector<int> dp(n, -1); 
        for(int i = 0; i < n; i++) {
            temp.push_back({arr[i].profit, arr[i].dead, arr[i].id});
        }
        
        int count = 0;
        int total = 0;
        
        // Sort jobs by profit in descending order
        sort(temp.begin(), temp.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        });
        
       
        for(int i = 0; i < temp.size(); i++){
            int profit = temp[i][0];
            int deadLine = temp[i][1];
            
           
            for(int j = min(deadLine - 1, n - 1); j >= 0; j--){
                if(dp[j] == -1) {
                    dp[j] = temp[i][2]; 
                    total += profit;
                    count++;
                    break; 
                }
            }
        }
        
        return {count, total};
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
