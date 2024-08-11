//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
  
   void mergeArray(vector<int>& arr1, vector<int>&arr2,vector<int>&mergedArray){
       int i =0;
       int j =0;
       
       while(i<arr1.size() && j<arr2.size()){
           
           if(arr1[i] >= arr2[j]) mergedArray.push_back(arr2[j++]);
           else mergedArray.push_back(arr1[i++]);
       }
       while(i<arr1.size()) mergedArray.push_back(arr1[i++]);
       while(j<arr2.size()) mergedArray.push_back(arr2[j++]);
       
       return ;
   }
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        vector<int>mergedArray;
        mergeArray(arr1,arr2,mergedArray);
        
        int size = mergedArray.size();
        
        if(size%2==0){
            int first  = mergedArray[size/2];
            int second = mergedArray[ (size/2) - 1];
            return first + second;
        }else{
            
            return mergedArray[size/2];
        }
        return -1;
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends
