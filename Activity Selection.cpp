//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &end) {
        vector<vector<int>> vc;
        int  n = start.size();
        for(int i=0;i<n;i++){

            vc.push_back({end[i],start[i]});

        }

        sort(vc.begin(),vc.end());

        int t=1;

        int st=vc[0][0];

        for(int i=1;i<n;i++){

            if(vc[i][1]>st){

                t++;

                st=vc[i][0];

            }

        }

        return t; // code here
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> finish;
        ss.str(input);
        while (ss >> num)
            finish.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends
