//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {
        int arr[4], j=0, temp=0;
        for(int i=0; i<str.size(); i++){
            if(str[i]=='/' || str[i]==','){
                arr[j] = temp;
                temp = 0;
                j++;
            }
            else if(isspace(str[i]))
                continue;
            else
                temp = temp*10 + str[i]-'0';
        }
        // for last number
        arr[3] = temp;
        
        // for debugging
        // cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<endl;
        
        if(arr[0]*arr[3] == arr[1]*arr[2])
            return "equal";
            
        else if(arr[0]*arr[3] < arr[1]*arr[2])
            return to_string(arr[2])+"/"+to_string(arr[3]);
        
        return to_string(arr[0])+"/"+to_string(arr[1]);
    }


};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends
