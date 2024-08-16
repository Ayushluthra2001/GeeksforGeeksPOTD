//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        int countZero = 0;
        for(auto i  : nums) if(i==0) countZero++;
        
        vector<long long int>ans(nums.size(),0);
        if(countZero>1) return ans;
       
        long long int temp =1;
        for(int i =0; i<nums.size(); i++){
            
            if(nums[i] != 0 ){
                //cout<<nums[i]<<" ";
                 temp = temp * nums[i];
            }
            
        }
        // cout<<endl;
        if(countZero == 1){
            
            for(int i=0; i<nums.size(); i++){
                if(nums[i] == 0) ans[i] = temp;
            }
            
            return ans;
        }
        //cout<<temp<<endl;
        for(int i=0; i<nums.size(); i++){
            ans[i] = temp / nums[i];
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
