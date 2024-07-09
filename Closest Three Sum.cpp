//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
//     -7 9 8 3 1 1
// 2
// -7 1 1 3 8 9 
  public:
int threeSumClosest(std::vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        
        int prevDiff = INT_MAX;
        int closestSum = INT_MIN;
        for(int i = 0; i < arr.size() - 2; i++){
            int start = i + 1; 
            int end = arr.size() - 1;
            while(start < end){
                int sum = arr[i] + arr[start] + arr[end];
                if(sum == target) return sum;
                int currentDiff = abs(sum - target);
                if(currentDiff < prevDiff || (currentDiff == prevDiff && sum > closestSum)){
                    prevDiff = currentDiff;
                    closestSum = sum;
                }
                if(sum < target){
                    start++;
                }
                else{
                    end--;
                }
            }
        }
        return closestSum;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends
