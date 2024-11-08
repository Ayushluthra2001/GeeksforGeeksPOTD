//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    private : 
    string sum(string num1 , string num2){
        int i = num1.length()-1;
        int j = num2.length()-1;
        int carry = 0;
        
        string result = "";
        while( i  >=0 || j >=0 || carry >=1){
            int value1 = i>=0 ? num1[i]-'0' : 0;
            int value2 = j>=0 ? num2[j]-'0' : 0;
            int currSum = value1 + value2 + carry;
            carry = currSum / 10;
            int lastDigit = currSum % 10;
            result += to_string(lastDigit);
            i--;
            j--;
            
        }
        reverse(result.begin(),result.end());
        return result;
    }
  public:
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        
        string num1 = "";
        string num2 = "";
        int i = 0;
        while(i < arr.size() && arr[i]==0)i++;
        if(i==arr.size()) return "0";
        
        int j = i;
        while(j < arr.size()){
            num1+=to_string(arr[j]);
            j++;
            if(j<arr.size()) num2+=to_string(arr[j]);
            j++;
        }
        
        return sum(num1 , num2);
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
